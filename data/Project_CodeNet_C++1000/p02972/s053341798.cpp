#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int a[210000],b[210000],n;
int main()
{

memset(a,0,sizeof(a));	
	cin>>n;
	for(int i=1;i<=n;i++)
	   cin>>b[i];
	   int sum=0,s=0;
	   for(int i=n;i>=1;i--)
	    {
	    	sum=0;
	    	for(int j=i+i;j<=n;j+=i)
	    	{
	    		sum+=a[j];
			}
			if(sum%2==b[i])a[i]=0;
			  else 
			  {
			  a[i]=1;
			  s++;}
		}
	printf("%d\n",s);
	for(int i=1;i<=n;i++)
	  if(a[i]==1)printf("%d ",i);
	
}