#include<iostream>
using namespace std;
int main()
{
  int x,y,z,k,t=0;
  cin>>x>>y>>z;
  cin>>k;
  while(x>=y)
  {
  	y=y*2;
  	t++;
  }
  while(y>=z)
  {
  	z=z*2;
  	t++;
  }
  if(t<=k)
  cout<<"Yes";
  else
  cout<<"No";
  return 0;
}