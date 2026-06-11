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
const int  MAXN =2e5+10;
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
typedef unsigned long long ull;
int vis[MAXN],a[MAXN],dist[MAXN];
int result[MAXN];
int main()
{
	int n,ans,need;
	ull k;
	scanf("%d %llu",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	queue<int>q;
	q.push(1);dist[1]=0;vis[1]=1;
	while(1)
	{
		int now=q.front();q.pop();
		int ne=a[now];
		vis[ne]++;
		int d=dist[now]+1;
		if(vis[ne]==2)
		{
			ans=d-dist[ne];
			need=ne;
			break;
		}
		dist[ne]=d;
		q.push(ne);
	}
	for(int i=0;i<ans;i++)
	{
		int now=need;
		result[i]=now;
	//	printf("re: %d \n",result[i]);
		need=a[now];
	}
	//printf("xunhuan: %d need: %d   %d\n",ans,need,dist[need]);
	if(k<dist[need])
	{
		int oo=0,ans1;
		queue<int>q1;q1.push(1);
		while(1)
		{
			int now=q1.front();q1.pop();
			int ne=a[now];
			oo++;
			if(oo==k)
			{
				ans1=ne;
				break;
			}
			q1.push(ne);
		} 
		printf("%d\n",ans1);
	}
	else
	{ 
    	int m=(k-dist[need])%ans;
    	//printf("%llu\n",m);
    	printf("%d\n",result[m]);
    } 
	return 0;
}