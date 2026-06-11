//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<map>
#include<vector>
#include<cmath>
#include<fstream>
#include <set>
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
const int  MAXN =2e5+10;
const int mod = 1e9 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int inf= 0x3f3f3f3f;
#define eps 1e-8
#define PI 3.1415926535898
#define lowbit(x) (x&(-x))
using namespace std ;
//getline(cin,s);
//set<ll>::iterator it;
//map<int,int>::iterator it;
//unordered_map
typedef long long ll;
ll a[MAXN],b[MAXN],sum1[MAXN],sum2[MAXN];
int main()
{
	int n,m;ll k,ans=0;
	scanf("%d %d %lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum1[i]=sum1[i-1]+a[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
		sum2[i]=sum2[i-1]+b[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(k>=sum1[i])
		{ 
		ll num=upper_bound(sum2+1,sum2+1+m,k-sum1[i])-sum2-1+i;
		ans=max(ans,num);
		} 
	}
	printf("%lld\n",ans);
	return 0;
}