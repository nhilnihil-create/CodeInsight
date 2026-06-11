#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007;

long long pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> A(k+1);
    for (int i = k; i > 0; --i) {
        ll t = pow(k/i, n);
        for (int j = i*2; j <= k; j += i) {
            t -= A[j];
        }
        A[i] = (t % MOD + MOD) % MOD;
    }
    ll ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += (A[i] * i) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}