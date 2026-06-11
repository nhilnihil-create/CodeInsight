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
typedef long long ll;
char s[MAXN];
int main()
{
	//前R后W 
	//大体思路 从前往后一遍 到第i个前面有几个r几个w 后面有几个r几个w 然后贪心 
	//因为需要前面R 后面W 所以前面w的个数个后面r的个数的max值 
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=inf,r=0,w=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='R') r++;
		else w++;
	}
	int r1=0,w1=0,r2=r,w2=w;
	for(int i=0;i<=n;i++)
	{
		ans=min(ans,max(w1,r2));
		if(i)
		{
			if(s[i]=='R')
			{
				r1++;
				r2--;
			}
			else
			{
				w1++;
				w2--;
			}
		} 
	}
	ans=min(ans,max(w1,r2));
	printf("%d\n",ans);
	return 0;
}