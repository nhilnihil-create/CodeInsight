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
const int  MAXN =2e5+7;
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
ll a[MAXN];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n;ll ans=0,tot=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];tot++;
	for(int i=2;i<=n;i++)
	{
		if(tot==n) break;
		ans+=a[i];tot++;
		if(tot==n) break;
		ans+=a[i];tot++;
		if(tot==n) break;
	}
	printf("%lld\n",ans);
	return 0;
 } 