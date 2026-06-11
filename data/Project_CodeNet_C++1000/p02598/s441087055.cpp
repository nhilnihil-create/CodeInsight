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
int k;
int n;
int a[MAXN];
int check(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(a[i]+x-1)/x-1;
	}
	//printf("x: %lld sum:%lld \n",x,sum);
	if(sum<=k) return 1;
	else return 0;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) 
	{
	    scanf("%d",&a[i]);
	} 
	int l=1,r=1e9;
	while(r>=l)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}