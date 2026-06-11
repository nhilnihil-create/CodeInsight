#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

int main() {
    int h, w, m; cin >> h >> w >> m;
    vector <map <int, bool> > cy(h + 1);
    vi sx(h + 1), sy(w + 1);
    FOR(i, 1, m) {
        int x, y; cin >> x >> y;
        cy[x][y] = 1, sx[x]++, sy[y]++;
    }
    priority_queue <pii> pq;
    FOR(i, 1, w)
        pq.push({sy[i], i});
    int ans = 0;
    FOR(i, 1, h) {
        if (sx[i]) {
            vpii rm;
            int tmx = 0;
            while (!pq.empty() && cy[i][pq.top().se]) {
                tmx = max(tmx, pq.top().fi - 1);
                rm.pb(pq.top()); pq.pop();
            }
            if (!pq.empty()) tmx = max(tmx, pq.top().fi);
            ans = max(ans, sx[i] + tmx);
            for (pii j : rm) pq.push(j);
        }
    }
    cout << ans << endl;
}