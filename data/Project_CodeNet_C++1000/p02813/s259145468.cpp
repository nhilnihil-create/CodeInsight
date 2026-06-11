#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int a[100],b[100],n,f[100],c[100];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x)
{
	while(x<=n)
	{
		c[x]+=1;
		x+=lowbit(x);
	}
}
int pre(int x)
{
	int sum=0;
	while(x)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
void init()
{
	f[0]=1;
	for(int i=1;i<=8;++i)
	{
		f[i]=f[i-1]*i;
	}
}
int cantor_exp(int p[],int len)
{
	int sum=0;
	for(int i=n;i>=1;--i)
	{
		int a=pre(p[i]);
		sum+=a*f[n-i];
		add(p[i]);
	}
	return sum;
}
int main()
{
	ios;
	cin>>n;
	init();
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
	}
	int s1,s2;
	s1=cantor_exp(a,n);
	memset(c,0,sizeof c);
	s2=cantor_exp(b,n);
	cout<<abs(s1-s2)<<'\n';
}