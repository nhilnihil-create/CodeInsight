#include<iostream>
using namespace std;
int sum(int a)
{
  if(a<=0) return 0;
  if(a==1) return 1;
  return a+sum(a-1);
}
int main()
{
  int a,b;
  cin>>a>>b;
  cout<<sum(a-1)+sum(b-1);
}