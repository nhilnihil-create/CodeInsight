#include<iostream>
using namespace std;
int main()
{
int n,m,r,t=0;
cin>>n>>m>>r;
for(int i=n;i<=m;i++)
{
  if(i%r==0)
  t++;
  }
  cout<<t;
  return 0;
}