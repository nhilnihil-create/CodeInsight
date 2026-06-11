#include<iostream>
#include<cstdio>
using namespace std;
int n;
const int MAXN=100100;
int a[MAXN];
long long p[MAXN];
long long sum,po;
int m[MAXN];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=2*a[i];
		sum+=p[i];
		if((i&1) && i!=n)  po+=p[i];
	}
	sum/=2;
	m[n]=sum-po;
	for(int i=n-1;i>=1;i--)
	{
		m[i]=p[i]-m[i+1];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<m[i]<<" ";
	}
	return 0;
}