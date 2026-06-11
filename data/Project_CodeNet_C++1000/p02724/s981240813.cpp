#include<iostream>
using namespace std;
int main()
{
  int a,ans=0;
  cin>>a;
  ans+=(a/500)*1000;
  a=a%500;
  ans+=(a/5)*5;
  cout<<ans;
}
