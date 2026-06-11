/*************************************************************************
	> File Name: 1.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/9/6 12:33:11
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
LL s;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	scanf("%lld",&s);
	LL x=sqrt(s),a,b;
	while(x*x<s) ++x;
	a=x*x-s;
	if(!a) b=0;
	else b=1;
	printf("0 0 %lld %lld %lld %lld\n",x,b,a,x);
	return 0;
}
