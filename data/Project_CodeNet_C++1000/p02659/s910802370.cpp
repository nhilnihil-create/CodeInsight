#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll a;
	double b;
	scanf("%lld %lf",&a,&b);
	b=b+1e-7;
	ll c=b*100;
	ll d=c*a/100;
	printf("%lld",d);
	return 0;
}