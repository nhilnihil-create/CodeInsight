/*************************************************************************
	> File Name: 3.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/7/13 13:29:28
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
int n,a[2020],num[2020];
LL sum[2020],ans=0;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	n=read();
	For(i,1,n){ a[i]=read(); num[a[i]]++; }
	For(i,1,2000) sum[i]=sum[i-1]+num[i];
	For(i,1,n)
		For(j,1,n){
			if(i==j) continue;
			int u=abs(a[i]-a[j]),v=a[i]+a[j];
			int tmp=sum[v-1]-sum[u]-1;
			u=a[i],v=a[j];
			if(u>v) swap(u,v);
			if(v<2*u) --tmp;
			ans+=tmp;
//			printf("%d %d %d\n",a[i],a[j],tmp);
		}
	cout<<ans/6<<endl;
	return 0;
}
