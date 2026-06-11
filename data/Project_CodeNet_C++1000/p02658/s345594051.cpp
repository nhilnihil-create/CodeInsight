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
unsigned long long  a[MAXN];
int main()
{
	int n,flag=1;unsigned long long  ans=1000000000000000000;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%llu",&a[i]);
	sort(a+1,a+1+n);
    if(a[1]==0)
    {
    	printf("0\n");
    	return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(ans/a[i-1]<a[i])
		{
			flag=0;
			break;
		}
		a[i]*=a[i-1];
	}
	if(flag)
	{
		printf("%llu\n",a[n]);
	} 
	else printf("-1\n");
	return 0;
}