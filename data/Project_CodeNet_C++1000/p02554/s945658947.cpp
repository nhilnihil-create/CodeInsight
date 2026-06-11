#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll QuickPow(ll a, ll b)
{
	ll res = 1;
	while ( b ) {
		if ( b & 1 ) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;  
	}

	return res;
}

int main()
{
	ll n;
	ll res = 0;
	cin >> n;
	res = (QuickPow(10, n) % MOD - QuickPow(9, n) * 2 % MOD + QuickPow(8, n) % MOD + MOD) % MOD;
	cout << res << endl;
	
	return 0;
}          