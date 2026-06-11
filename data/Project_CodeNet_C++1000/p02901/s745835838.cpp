/*************************************************************************
	> File Name: 3.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/7/13 15:13:56
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
const LL oo=1e15;
int a[2020],b[2020];
LL dp[1<<20];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int u,v,n,m;
	n=read(); m=read();
	For(i,1,m){
		a[i]=read(); u=read();
		int s=0;
		while(u--){
			v=read();
			s|=(1<<(v-1));
		}
		b[i]=s;
	}
	For(i,1,1<<n) dp[i]=oo;
	dp[0]=0;
	For(i,1,m) For(j,0,(1<<n)-1){
		dp[j|b[i]]=min(dp[j]+a[i],dp[j|b[i]]);
//		cout<<j<<" "<<dp[j]<<endl;
	}
	if(dp[(1<<n)-1]==oo) dp[(1<<n)-1]=-1;
	cout<<dp[(1<<n)-1];
	return 0;
}
