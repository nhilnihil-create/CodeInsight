#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
const int N = 3e5+ 2, mod = 1e9 + 7;

long long binpow(long long a, long long b, long long m = mod) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


void solve() {
     int n;
     cin >> n;
     ll ans = (binpow(10, n) - (2*binpow(9, n))%mod + mod)%mod;
     cout << (ans + binpow(8, n))%mod << '\n';
}    


int main() {
	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		// cout << "Case #:" << tc << " ";
		solve();
	}
}