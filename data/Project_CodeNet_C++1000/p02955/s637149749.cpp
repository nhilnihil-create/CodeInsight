#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    ll sum = 0;
    rep(i, N) sum += a[i];
    set<ll> candidates;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            candidates.insert(i);
            candidates.insert(sum / i);
        }
    }
    ll ans = 1;
    for (ll x : candidates) {
        ll need;
        { // calc need
            vector<ll> r(N);
            rep(i, N) r[i] = a[i] % x;
            sort(r.begin(), r.end());
            ll B = 0; // 正にする回数
            rep(i, N) B += x - r[i];
            ll A = 0; // 負にする回数
            need = 1e18;
            rep(i, N) {
                // 正負の区切り位置を全部試す
                A += r[i];
                B -= x - r[i];
                if(A == B) need = min(need, A);
            }
        }
        if (need <= K) ans = max(ans, x);
    }
    cout << ans << endl;
}
