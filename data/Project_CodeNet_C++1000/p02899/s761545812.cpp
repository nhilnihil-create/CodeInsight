/*************************************************************************
	> File Name: 1.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/7/13 12:02:38
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
const int maxx=1e5+10;
struct node{
	int x,id;
}a[maxx];
bool cmp(node x,node y){
	return x.x<y.x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int n=read();
	For(i,1,n){
		a[i].x=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	For(i,1,n) printf("%d ",a[i].id);
	return 0;
}
