#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, s, n) for (int i = s; i < n; i++)
#define all(v) v.begin(), v.end() // sort(all(array))
#define INF 1000000000
#define mod 1000000007
#define EPS 0.0001
using namespace std;
using ll = long long;
using vi = vector<int>; //vi array(要素数, 初期値)
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vc = vector<char>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vi>; //vvi table(行数, vi(列数, 初期値))
using vvc = vector<vc>;
using vvs = vector<vs>;
using vvb = vector<vb>;

int main() {
    int h, w, k; cin >> h >> w >> k;
    vs masu(h);
    rep(i, h) cin >> masu[i];

    int ans = 0;
    rep(mask_h, 1 << h) rep(mask_w, 1 << w) {
        int cnt = 0;
        rep(i, h) rep(j, w) {
            if (mask_h & (1 << i) || mask_w & (1 << j)) {
                continue;
            }
            if (masu[i][j] == '#') {
                cnt++;
            }
        }
        if (cnt == k) {
            ans++;
        }
    } 
    cout << ans << endl;
}