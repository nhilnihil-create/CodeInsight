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
const int  MAXN =1e6+10;
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
int n,a[MAXN];
//unordered_map<int,int>mp;
//int need[MAXN];
//map<int,int>mp;
//TLE了 可能思路：每个数*一个数的形式 判断所得的num 然后与n比较 
//这道题注意点：O() 在数据范围小的情况下 尽量开普通数组 然后 是unordered_map（查找快，无序） 最后是map
//自己老是习惯开map 然后tle 不知所措 
int main()
{
	int ans=0;
	for(int i=1;i<=5;i++) 
	{
	    scanf("%d",&a[i]);
	    if(!a[i]) ans=i;
	} 
	printf("%d\n",ans);
	return 0;
} 