#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
    vector<vector<int>> c(26);
    rep(i, n) c[s[i]-'a'].push_back(i);
    rep(i, n) c[s[i]-'a'].push_back(i+n);
    int p = 0;
    ll ans = 0;
    rep(i, m) {
        int now = t[i] - 'a';
        int l = c[now].size();
        if (l == 0) {
            cout << -1 << endl;
            return 0;
        }
        p = *lower_bound(c[now].begin(), c[now].end(), p) + 1;
        if (p >= n) {
            p -= n;
            ans += n;
        }
    }
    cout << ans + p << endl;
    return 0;
}
