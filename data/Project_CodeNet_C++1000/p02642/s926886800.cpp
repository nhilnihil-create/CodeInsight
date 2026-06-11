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
typedef long long ll;
//ai/aj!=0(1=<j<=n) 
int need[1000005];
int a[MAXN];
int main()
{
	int n;
	int max1=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),max1=max(max1,a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j<=max1;j+=a[i])
		{
			need[j]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(need[a[i]]==1) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 