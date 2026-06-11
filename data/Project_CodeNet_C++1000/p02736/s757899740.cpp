#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[1000005];
char s[1000005];
ll b[1000005];
int main()
{
	ll n;
	scanf("%lld",&n);
	scanf(" %s",s);
	bool one=0;
	for(ll i=0;i<n;i++)
	{
		a[i]=s[i]-'1';
		if(a[i]==1) one=true;
	}
	if(!one)
	{
		for(ll i=0;i<n;i++) a[i]/=2;
	}
	else
	{
		for(ll i=0;i<n;i++) a[i]%=2;
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		if(((n-1)&i)==i)
		{
			ans^=a[i];
		}
	}
	if(!one)
	{
		ans*=2;
	}
	printf("%lld",ans);
}