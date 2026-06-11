#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> hs(h), ws(w);
    set<P> s;
    rep(i, m) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        hs[r]++;
        ws[c]++;
        s.emplace(r, c);
    }
    int mh = 0;
    int mw = 0;
    rep(i, h) mh = max(mh, hs[i]);
    rep(j, w) mw = max(mw, ws[j]);
    vector<int> is, js;
    rep(i, h) if(mh == hs[i]) is.pb(i);
    rep(j, w) if(mw == ws[j]) js.pb(j);
    int ans = mh + mw;
    for(int i : is) {
        for(int j : js) {
            if(s.count(P(i, j))) continue;
            cout << ans << endl;
            return 0;
        }
    }
    --ans;
    cout << ans << endl;
    return 0;
}