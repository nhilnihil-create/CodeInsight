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
int main()
{
	//c^2=a^2+b^2-2*a*b*cos(x);
	double a,b,h,w;
	scanf("%lf%lf%lf%lf",&a,&b,&h,&w);
	double ans1=0,ans2=0,ans;
	ans1=30*h;ans2=6*w;
	ans=abs(ans1-ans2+w/2);
	if(ans>=180) ans=360-ans;
//	printf("%lf\n",cos(PI*ans/180));
	double result;
	result=sqrt(a*a+b*b-2*a*b*cos(PI*ans/180));
	printf("%.10lf",result);
	return 0;	
} 