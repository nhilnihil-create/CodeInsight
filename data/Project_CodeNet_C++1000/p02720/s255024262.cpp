#include<bits/stdc++.h>
using namespace std;
int k;
int sum=9;
int a[11];
void sxqn(int n,int m,int p)
{
	if(m<0)return;
	if(m>9)return;
	a[p]=m;
	if(p==n)
	{
	  sum++;
	  if(sum==k)
	  {
	  	for(int i=1;i<=p;i++)
	  	  cout<<a[i];
	  	exit(0);
	  }
	  return;
	}
	sxqn(n,m-1,p+1);
	sxqn(n,m,p+1);
	sxqn(n,m+1,p+1);
}
int main()
{
	cin>>k;
	if(k<10)
	{
	  cout<<k;
	  return 0;
	}
	for(int i=2;i<=10;i++)
	  for(int j=1;j<=9;j++)
	    sxqn(i,j,1);
	return 0;
}