#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int NMAX = 2e5 + 10;
const int MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
	ll n;
	ll ans;
	scanf("%lld",&n);
	ans = n;
	for(register ll i = 1;i * i <= n;i++)
		if(n % i == 0)
			ans = min(ans , i + n/i - 2);
	printf("%lld\n",ans );
	return 0;
}