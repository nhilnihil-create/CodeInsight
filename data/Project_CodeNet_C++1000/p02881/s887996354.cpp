#include<cstdio>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int main()
{
	ll n;
	scanf("%lld",&n);
	ll k=sqrt(n)+1;
	while(n%k!=0)k--;
	printf("%lld",k+n/k-2);
	return 0;
}
