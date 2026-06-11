#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N), C(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> C[i];
    rep(i, N) P[i]--;

    ll ans = -1e18;

    rep(si, N) {
        int x = si;
        vector<int> s;
        ll tot = 0;
        while (true) {
            x = P[x];
            s.push_back(C[x]);
            tot += C[x];
            if (x == si) break;
        }

        int l = s.size();
        ll t = 0;
        rep(i, l) {
            t += s[i];
            if (i + 1 > K) break;
            ll now = t;
            if (tot > 0) {
                ll e = (K - (i + 1)) / l;
                now += tot * e;
            }
            ans = max(ans, now);
        }
    }

    cout << ans << endl;

    return 0;
}