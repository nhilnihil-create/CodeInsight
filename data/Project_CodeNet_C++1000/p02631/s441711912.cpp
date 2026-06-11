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
int need[MAXN][64];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ll a;
		scanf("%lld",&a);
		int to=0;
		while(a)
		{
			need[i][to++]=a%2;
			a/=2;
		}
	}
	for(int i=63;i>=0;i--)
	{
		int num1=0,num2=0;
		for(int j=1;j<=n;j++)
		{
			if(need[j][i]) num1++;
			else num2++;
		}
		if(num1%2)// 奇数 
		{
			for(int j=1;j<=n;j++)
			{
				need[j][i]^=1;
			}
		}
	} 
	for(int i=1;i<=n;i++)
	{
		ll sum=0,num=1;
		for(int j=0;j<64;j++)
		{
			if(need[i][j]) sum+=num;
			num*=2;
		}
		if(i==1) printf("%lld",sum);
		else printf(" %lld",sum);
	}
}