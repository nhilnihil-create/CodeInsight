#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll K, Q; cin >> K >> Q;
    vl d(K);
    rep(i,K) cin >> d[i];
    rep(i,Q) {
        ll N, X, M;
        cin >> N >> X >> M; N--;
        ll a1 = X, an = X, ans = N;
        rep(k,K) {
            ll D = d[k] % M;
            ll cnt = N/K + (N%K > k);
            an += D * cnt;
            if (D == 0) ans -= cnt;
        }
        ans -= (an/M - a1/M);
        cout << ans << endl;
    }
    return 0;
}
