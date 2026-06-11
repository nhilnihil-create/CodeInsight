#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll N, K;
    cin >> N >> K;
    ll A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    if(K == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++) {
        A[i]--;
        A[i] %= K;
    }
    ll ans = 0;
    map<ll, ll> cnt;
    cnt[0] = 1;
    ll sum[N + 1] = {};
    for(int i = 0; i < N; i++) {
        sum[i + 1] = (sum[i] + A[i]) % K;
        ans += cnt[sum[i + 1]]++;
        if(i + 2 - K >= 0) {
            cnt[sum[i + 2 - K]]--;
        }
    }
    cout << ans << endl;
    return 0;
}