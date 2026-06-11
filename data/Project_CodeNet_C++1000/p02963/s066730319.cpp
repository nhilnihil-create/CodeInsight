/*************************************************************************
	> File Name: 1.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/7/15 15:35:33
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
const LL maxx=1e9;
LL a,b,c,d;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	LL n;
	scanf("%lld",&n);
	if(n<=maxx) printf("0 0 %lld 0 0 1\n",n);
	else{
		a=d=sqrt(n);
		if(a*d<n) a++;
		if(a*d<n) d++;
		LL x=a*d-n;
		if(x<=maxx) b=1,c=x;
		else{
			for(LL i=x/maxx;i<=sqrt(x);++i)
				if(x%i==0 && x/i<=maxx){
					b=i;  c=x/i;
					break;
				}
		}		
		printf("0 0 %lld %lld %lld %lld",a,b,c,d);
	}	
	return 0;
}
