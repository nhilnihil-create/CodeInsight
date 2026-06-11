#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<ll>> xdp(h, vector<ll>(w, 0));
    rep(i, h) {
        ll idx = -1, cnt = 0;
        rep(j, w) {
            if (s[i][j] == '#') {
                if (idx != -1) {
                    xdp[i][idx] += cnt;
                    xdp[i][j] -= cnt;
                    idx = -1;
                    cnt = 0;
                }
            }
            else {
                cnt++;
                if (idx == -1) {
                    idx = j;
                }
            }
        }
        if (idx != -1) xdp[i][idx] += cnt;
    }
    rep(i, h) {
        reps(j, 1, w) {
            xdp[i][j] += xdp[i][j - 1];
        }
    }
    vector<vector<ll>> ydp(h, vector<ll>(w, 0));
    rep(i, w) {
        ll idx = -1, cnt = 0;
        rep(j, h) {
            if (s[j][i] == '#') {
                if (idx != -1) {
                    ydp[idx][i] += cnt;
                    ydp[j][i] -= cnt;
                    idx = -1;
                    cnt = 0;
                }
            }
            else {
                cnt++;
                if (idx == -1) {
                    idx = j;
                }
            }
        }
        if (idx != -1) ydp[idx][i] += cnt;
    }
    rep(i, w) {
        reps(j, 1, h) {
            ydp[j][i] += ydp[j - 1][i];
        }
    }
    ll ans = 0;
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#') continue;
            ans = max(ans, xdp[i][j] + ydp[i][j] - 1);
        }
    }
    cout << ans << endl;
    // rep(i, h) rep(j, w) printf("%lld%s", xdp[i][j], (j == (w - 1)) ? "\n" : " ");
    return 0;
}
