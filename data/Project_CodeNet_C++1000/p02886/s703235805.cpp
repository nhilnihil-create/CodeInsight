#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::vector<long long> d) {
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            ans += d[i] * d[j];
        }
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> d(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &d[i]);
    }
    solve(N, std::move(d));
    return 0;
}
