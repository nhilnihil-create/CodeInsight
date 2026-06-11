#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const long long MOD = 998244353;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void solve(long long N, std::vector<long long> D) {
    vector<ll> distance(N);
    rep(i, N) {
        if ((i == 0 && D[i] != 0) || (i != 0 && D[i] == 0)) {
            cout << 0 << endl;
            return;
        }
        distance[D[i]]++;
    }
    ll ans = 1;
    for (ll i = 1; i < N; i++) {
        ans = ans * modpow(distance[i - 1], distance[i], MOD);
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> D(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &D[i]);
    }
    solve(N, std::move(D));
    return 0;
}
