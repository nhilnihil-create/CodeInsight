#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(a) (int)a.size()
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;

auto rnd = bind(uniform_int_distribution<int>(1, 10000), mt19937(time(0)));

bool is_prime (int n, int p) {
    for (int i = 2; i <= sqrt(n) && i <= p; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

ll binpow (ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow(a, n - 1) * a;
	else {
		ll b = binpow (a, n / 2);
		return b * b;
	}
}

int main()
{
    boost;
    ll x, k, d; cin >> x >> k >> d;
    x = abs(x);
    ll moves = min(x / d, k);
    x -= moves * d;
    k -= moves;
    if (k % 2 == 0) {
        cout << x;
    }
    else {
        cout << d - x;
    }
    return 0;
}

