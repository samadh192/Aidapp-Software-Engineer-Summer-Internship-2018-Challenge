/*
The code is written in C++. Contains a total of two functions.
The following is a brute force approach
*/

#include<iostream>
using namespace std;
double n,health,damage;//declared as global variables
//n is the number of monkeys,health is initial health and damage is initial damage
bool isAlive()//function to check if the protagonist is alive
{
  if ((health>0)&&(damage<1000000))
  return true;
  else
  return false;
}
int main()
{
  int A[1000000];
  health=2000;
  damage=1;
  cin>>n;//take the value of n/total monkeys
  for (int i=1;i<=n;i++)
    cin>>A[i];//Array to take n values from user which denote he damage dealt by n monkeys
  int marker=0;//current position of protagonist in the line
  int max_defeated=0;//initial valuse to maximum monkeys defeated
  i=0;//start position of protagonist
  int defeated=0;//number of monkeys
  while((marker<=999999)&&(max_defeated<=n-marker))
  /*
  Explanation for while loop conditions:
  -marker should not cross 999999 since this will be the 1000000th monkeys
  -once max_defeated is greater than the number of monkeys left then we dont have to check any
  further since the number of monkeys left to check will never be greater than max_defeated
  */
  {
    while((isAlive())&&(i<n))//while protagonist is alive and his position is not greater than 1000000
    {
      health-=A[i];
      damage*=A[i];
      i++;
      defeated++;
      /*
      -loop runs till the conditons are true
      -for each monkey encountered health is reduced by A[i] amount
      -for each monkey encountered damage is multiplied by A[i] amount
      -increment postion after defeating each monkey and increment number of monkeys defeated
      */
    }
    if (defeated>max_defeated)
      max_defeated=defeated;//max_defeated will contain the maximum number of monkeys defeated
    marker=i;//finally marker will contain position after defeating max_defeated number of monkeys
    health=2000;//reset health and damage after each iteration
    damage=1;
  }
  /*marker-max_defeated will contain the postion for the protagonist to start so
  that he defeats the maximum number of monkeys
  */
}
