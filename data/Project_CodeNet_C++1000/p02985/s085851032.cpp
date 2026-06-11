/*************************************************************************
	> File Name: 1.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/9/6 13:41:01
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
const int maxx=5e5+10,mod=1000000007;
int n,k,be[maxx],ne[maxx],to[maxx],dep[maxx],e=0;
LL val[maxx],ans=1;
void add(int x,int y){
	to[++e]=y;
	ne[e]=be[x];
	be[x]=e;
}
void dfs(int x,int fa){
	LL j=0;
	for(int i=be[x];i;i=ne[i]){
		int go=to[i];
		if(go==fa) continue;
		dep[go]=dep[x]+1;
		if(dep[go]==1) val[go]=k-1;
		else val[go]=k-2;
		val[go]-=j;
		++j;
		dfs(go,x);
	}
}
void get_ans(int x,int fa){
	if(val[x]<=0) ans=0;
	ans=ans*val[x]%mod;
	for(int i=be[x];i;i=ne[i]){
		int go=to[i];
		if(go==fa) continue;
		get_ans(go,x);
	}
}
		
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	n=read(); k=read();
	For(i,1,n-1){
		int u=read(), v=read();
		add(u,v); add(v,u);
	}
	val[1]=k; dep[1]=0;;
	dfs(1,0);
	get_ans(1,0);
	printf("%lld\n",ans);
	return 0;
}
