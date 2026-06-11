#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

ll N;
vector<ll> A;
int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    // 桁ごとに計算する
    ll ans = 0;
    for (int i = 0; i < 60; i++) {
        // ビットが立っているかず

        ll cnt = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] >> i & 1) cnt++;
        }

        ll pat = cnt * (N - cnt) % MOD;
        // cout << cnt << endl;
        // i 回2をかける
        for (int j = 0; j < i; j++) {
            pat *= 2;
            pat %= MOD;
        }
        ans += pat;
        ans %= MOD;
    }
    cout << ans << endl;
}