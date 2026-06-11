#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
  long long int a,b;
  cin>>a>>b;
  if(abs(a-b)%2==0)
  {
   long long int sum=abs(a-b)/2;
    if(a>b)
    {
      cout<<abs(sum-a);
    }
    else
    {
      cout<<abs(sum-b);
    }
  }
  else
  {
    cout<<"IMPOSSIBLE";
  }
}