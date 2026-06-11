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
char s[MAXN];
int main()
{
	ll n;
	int tot=0;
	scanf("%lld",&n);
	ll sum=0;
	while(n>0)
	{
		int x=(n-1)%26+1;
		s[tot++]=x+'a'-1;
		n-=x;
		n/=26;
	}
	for(int i=tot-1;i>=0;i--) printf("%c",s[i]);
}