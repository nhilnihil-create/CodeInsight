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
const int  MAXN =5e5+10;
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
//c>b>a
int main()
{
	int a,b,c,k;int ans=0;
	scanf("%d %d %d %d",&a,&b,&c,&k);
	while(a>=b)
	{
		b*=2;
		ans++;
	}
	while(b>=c)
	{
		c*=2;
		ans++;
	}
	if(ans<=k) printf("Yes\n");
	else printf("No\n");
} 