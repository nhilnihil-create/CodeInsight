#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=100;
int x;
int main()
{
	scanf("%d",&x);
	int a=x/500;x%=500;
	int b=x/5;
	long long ans=1000*a*1LL+5*b;
	printf("%lld\n",ans);
	return 0;
}
