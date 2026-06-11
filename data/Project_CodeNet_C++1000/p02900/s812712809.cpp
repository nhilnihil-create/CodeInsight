/*************************************************************************
	> File Name: 1.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/7/13 12:59:34
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
const int maxx=1e6;
bool isprime[maxx+20];
LL pri[maxx+20],cnt=0;
LL gcd(LL x,LL y){
	return !y?x:gcd(y,x%y);
}

void findprime(){
	memset(isprime,true,sizeof(isprime));
	for(LL i=2;i<=maxx;++i){
		if(isprime[i]){
			pri[++cnt]=i;
		}
		for(LL j=1;j<=cnt;++j){
			if(i*pri[j]>maxx) break;
			isprime[i*pri[j]]=0;
			if(i%pri[j]==0) break;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	findprime();
	LL x,y,d;
	scanf("%lld%lld",&x,&y);
	d=gcd(x,y);
//	cout<<d<<endl;
	int i=1,ans=0;  
	while(i<=cnt && d>1){
		if(d%pri[i]==0){
			++ans;
			while(d%pri[i]==0) d/=pri[i];
		}
		++i;
	}
	if(d>1) ++ans;
	printf("%d\n",ans+1);
	return 0;
}
