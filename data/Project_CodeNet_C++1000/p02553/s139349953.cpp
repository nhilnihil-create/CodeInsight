#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#define LL long long
#define N 1000001
#define NN 2002
using namespace std;
LL a,b,c,d,i;
LL f[N];
int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	f[1]=a*c,f[2]=a*d,f[3]=b*c,f[4]=b*d;
	printf("%lld",max(f[1],max(f[2],max(f[3],f[4]))));
	return 0;
}