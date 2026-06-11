#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll MOD = 998244353;
    int N;
    cin >> N;
    vector<ll> D(N);
    map<ll, ll> ma;
    rep(i, N) {
        cin >> D[i];
        ma[D[i]]++;
    }

    if (D[0] != 0) {
        cout << 0 << endl;
        return 0;
    }
    if (ma[0] > 1){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for (auto m : ma) {
        if (m.first == 0)
            continue;
        else {
            ans *= modpow(ma[m.first - 1], m.second, MOD);
            ans %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}