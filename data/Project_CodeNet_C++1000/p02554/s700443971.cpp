#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
#define LARGE 1000000007
const int MOD = 1e9 + 7;

ll power_mod(ll a, ll n, int p = MOD) {
    ll ret = 1;
    for (; n; n >>= 1) {
    if (n & 1) ret = ret * a % p;
    a = a * a % p;
    }
    return ret;
}

int main() {
    ll n;
    cin >> n;
    ll ret = power_mod(10, n);
    ret = (ret + MOD - power_mod(9, n)) % MOD;
    ret = (ret + MOD - power_mod(9, n)) % MOD;
    ret = (ret       + power_mod(8, n)) % MOD;

    cout << ret << endl;

	return 0;
}
