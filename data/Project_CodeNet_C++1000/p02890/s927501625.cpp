/*************************************************************************
	> File Name: 5.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/7/13 16:51:31
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define LL long long
using namespace std;
int read(){
	char x=getchar(); int u=0,fg=0;
	while(!isdigit(x)){ if(x=='-') fg=1; x=getchar(); }
	while(isdigit(x)){ u=(u<<3)+(u<<1)+(x^48); x=getchar(); }
	return fg?-u:u;
}
const int maxx=5e5+10;
int n,a[maxx],b[maxx],cnt=0,sum=0;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	n=read();
	For(i,1,n){
		int u=read();
		a[u]++;
		b[a[u]]++;
	}
	For(i,1,n) b[i]=b[i-1]+b[i];
	For(k,1,n){
		int l=0,r=n,mid;
		while(l<=r){
			mid=(l+r)>>1;
//printf("%d %d\n",l,r,mid);
			if((LL)k*mid<=b[mid]) l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",l-1);
	}
	return 0;
}
