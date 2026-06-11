#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n;
ll qpow(ll x, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    if(n == 1) cout << 0 << endl;
    else 
    {
    	ll a0 = qpow(9, n), a9 = qpow(9, n), a09 = qpow(8, n), tmp = qpow(10, n);
    	cout << (tmp - a0 - a9 + 2 * mod + a09) % mod << endl;
	}
	return 0;
}
