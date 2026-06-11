#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    vector<vector<pint>> g (n);
    int a[n - 1], b[n - 1], c[n - 1];
    rep (i, 0, n - 1) c[i] = -1;
    int start = 0;
    rep (i, 0, n - 1) {
        cin >> a[i] >> b[i];
        g[--a[i]].push_back ({--b[i], i});
        g[b[i]].push_back ({a[i], i});
    }
    queue<int> q; //次の場所をためる
    q.push (0);
    int Cnt[n] = {};
    while (!q.empty()) {
        int cnt = 0;
        int now = q.front();
        q.pop();
        for (auto next : g[now]) {
            if (c[next.second] == -1) {
                // cout << now << " " << next.first << Cnt[next.first] << "\n";
                if (Cnt[now] == ++cnt) {
                    Cnt[next.first] = ++cnt;
                    c[next.second] = cnt;
                } else {
                    Cnt[next.first] = cnt;
                    c[next.second] = cnt;
                } /*
                 if (Cnt[next.first] == 0) {
                     Cnt[next.first] == ++cnt;
                     c[next.second] = cnt;
                 } else {
                     if (Cnt[next.first] == ++cnt) {
                         c[next.second] = ++cnt;
                     }
                 }*/
                // cout << cnt << "\n";
                q.push (next.first);
            }
        }
    }
    int ans = 0;
    rep (i, 0, n - 1) { ans = max (ans, c[i]); }
    cout << ans << "\n";
    rep (i, 0, n - 1) cout << c[i] << "\n";
}