#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> is(26);
    rep(i,n) is[s[i]-'a'].push_back(i);
    rep(i,n) is[s[i]-'a'].push_back(i+n);
    ll ans = 0;
    int p = 0;
    rep(i,m) {
        int c = t[i]-'a';
        if (is[c].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        p = *lower_bound(is[c].begin(), is[c].end(), p) + 1;
        if (p >= n) {
            p -= n;
            ans += n;
        }
    }
    ans += p;
    cout << ans << endl;
    return 0;
}