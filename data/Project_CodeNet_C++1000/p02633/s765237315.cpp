#include<iostream>
using namespace std;
int main()
{
  int n,i=1;
  cin>>n;
  while(true)
  {
    if((n*i)%360==0)
    {
      cout<<i;
      break;
    }
    i++;
  }
 return 0;
}  