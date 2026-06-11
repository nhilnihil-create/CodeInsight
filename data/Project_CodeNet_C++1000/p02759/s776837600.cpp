#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  for(int i=2;i<=100;i+=2)
  {
    if(n<=i)
    {
      cout<<i/2;
      return 0;
    }
  }
}