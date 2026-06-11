#include<bits/stdc++.h>
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
const int  MAXN =1e5+10;
const long long  mod = 1e14 ;
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
int a[15][15],c[15];
int main()
{
	int ans=inf;
	int n,m,x;
	scanf("%d %d %d",&n,&m,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for(int i=1;i<2<<n;i++)
	{
		int num=i;
		int vis[15],index=1;
		while(num)
		{
			vis[index++]=num%2;
			num/=2;
		}
		int need[15]={0},sum=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j])
			{
				sum+=c[j];
				for(int k=1;k<=m;k++)
				{
					need[k]+=a[j][k];
				}
			}
		}
		int flag=1;
		for(int j=1;j<=m;j++)
		{
			if(need[j]<x)
			{
				flag=0;
				break;
			}
		}
		if(flag) ans=min(ans,sum);
	}
	if(ans==inf) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}