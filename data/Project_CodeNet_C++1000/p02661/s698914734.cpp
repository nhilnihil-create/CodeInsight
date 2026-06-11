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
//unordered_map<int,int>mp;
//int need[MAXN];
//map<int,int>mp;
//TLE了 可能思路：每个数*一个数的形式 判断所得的num 然后与n比较 
//这道题注意点：O() 在数据范围小的情况下 尽量开普通数组 然后 是unordered_map（查找快，无序） 最后是map
//自己老是习惯开map 然后tle 不知所措 
ll a[MAXN],b[MAXN];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n;
	ll ans=0;
	ll max1=0,min1=INF;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	    scanf("%lld %lld",&a[i],&b[i]);
		max1=max(max1,b[i]);
		min1=min(min1,a[i]);
	} 
	sort(a+1,a+1+n);
	sort(b+1,b+1+n,cmp);
	if(n%2)  printf("%lld\n",b[(n+1)/2]-a[(n+1)/2]+1);
	else printf("%lld\n",b[n/2]+b[n/2+1]-a[n/2]-a[n/2+1]+1);
	return 0;
} 