#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
    int n, k; cin >> n >> k;
    vector<int> p(n), c(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> c[i];
    rep(i, n) p[i]--;
    ll ans = -llINF;
    rep(si, n) {
        int x = si;
        vector<int> s;
        ll tot = 0;
        while (1) {
            x = p[x];
            s.push_back(c[x]);
            tot += c[x];
            if (si == x) break;
        }
        int l = s.size();
        ll now = 0;
        rep(i, l) {
            now += s[i];
            if (i >= k) break;
            if (0 < tot) {
                ll e = (k - i - 1) / l;
                ans = max(ans, now + tot * e);
            }
            else ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}