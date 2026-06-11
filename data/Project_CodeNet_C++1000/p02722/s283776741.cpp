#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll mod = 1000000007;
const double eps = 1e-8;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

bool check(ll N, ll K) {
    while (N % K == 0) N /= K;
    N %= K;
    return N == 1;
}

int main() {
    ll N;
    cin >> N;

    ll ans = 0;

    // 最初割り切れない場合
    vector<ll> d1;
    for (ll i=1; i*i<=N-1; ++i) {
        if ((N-1) % i == 0) {
            if (i != 1) d1.push_back(i);
            if (i * i != N-1) d1.push_back(N / i);
        }
    }
    ans += d1.size();

    // 最初割り切れる場合
    vector<ll> d2;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            if (i != 1) d2.push_back(i);
            if (i * i != N) d2.push_back(N / i);
        }
    }
    for (ll k: d2) {
        if (check(N, k)) ans ++;
    }

    cout << ans << endl;

    return 0;
}