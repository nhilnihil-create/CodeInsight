#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    ll N, K; cin >> N >> K;
    vl P(N);
    rep(i, N) {
        cin >> P[i];
        P[i]--;
    }
    vl C(N); rep(i, N) cin >> C[i];

    ll ans = -LINF;
    rep(si, N) {
        ll x = si;
        vl s;
        ll total = 0;
        while (1) {
            x = P[x];
            total += C[x];
            s.push_back(C[x]);
            if (x == si) break;
        }

        ll l = s.size();
        ll t = 0;
        rep(i, l) {
            t += s[i];
            if (i + 1 > K) break;
            ll now = t;
            if (total > 0) {
                ll e = (K - (i + 1)) / l;
                now += total * e;
            }
            ans = max(now, ans);
        }
    }
    cout << ans << endl;
}
