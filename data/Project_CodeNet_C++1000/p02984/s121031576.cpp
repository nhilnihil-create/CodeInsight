/*************************************************************************
	> File Name: 3.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/7/13 13:53:12
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
const int maxx=2e5+10;
int n;
LL a[maxx],b[maxx];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int n=read();
	LL x=0;
	For(i,1,n){
		a[i]=read();
		if(i&1) x+=a[i];
		else x-=a[i];
	}
	b[1]=x;
	For(i,1,n-1)
		b[i+1]=2*a[i]-b[i];
	For(i,1,n) printf("%lld ",b[i]);
	return 0;
}
