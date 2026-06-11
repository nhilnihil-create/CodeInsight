#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int INF = 1001001001;
const double PI = acos(-1);

#define rep(i, n)  for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()


int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> is(26);
    rep(i, n) is[s[i] - 'a'].push_back(i);
    rep(i, n) is[s[i] - 'a'].push_back(i+n);
    ll ans = 0;
    int p = 0;
    rep(i, m) {
        int c = t[i] - 'a';
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
