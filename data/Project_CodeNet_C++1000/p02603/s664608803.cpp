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
const int mod = 1e14 ;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int inf= 0x3f3f3f3f;
#define eps 1e-8
#define PI 3.1415926535898
#define lowbit(x) (x&(-x))
using namespace std ;
//getline(cin,s);
//set<ll>::iterator it;
//map<int,int>::iterator it;
typedef long long ll;
ll a[100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll min1=a[1];ll ans=1000;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>min1)
		{
			ll sum=ans/min1,result=ans%min1;
			//printf("%d %d %d %d %d\n",a[i],sum,result,ans,min1);
			ans=sum*a[i]+result;
			min1=a[i];
			//printf("%d %d %d\n",sum,result,a[i]);
			//printf("ans: %d\n",ans);
		}
		min1=min(min1,a[i]);
	}
	printf("%lld\n",ans);
	return 0;
} 