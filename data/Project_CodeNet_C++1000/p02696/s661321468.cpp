#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

ll solve(ll A, ll B, ll N) {
    ll ma = 0;
    for (ll x = 0; x <= N; x++) {
        ll ans = (A * x) / B - A * (ll)(x/B);
        if (ma < ans) {
            ma = ans;
            if (ma > 99999) printf("%ld: %ld\n", x, ma);
        }
//        printf("%ld: %ld\n", x, A * x / B - A * (ll)(x / B));
    }
    return ma;
}

ll solve2(ll A, ll B, ll N) {
    ll x = min(N, B-1);
    return A * x / B - A * (ll)(x/B);
}

int main() {
    ll A, B, N; cin >> A >> B >> N;
//    cout << solve(A, B, N) << endl;
//    for (ll x = N - 100; x <= N; x++)

    cout << solve2(A, B, N) << endl;
}
