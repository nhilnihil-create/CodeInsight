#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll a,b,n;
	scanf("%lld%lld%lld",&a,&b,&n);
	printf("%lld\n",(a*(min(b-1,n)))/b-a*((min(b-1,n))/b));
}
