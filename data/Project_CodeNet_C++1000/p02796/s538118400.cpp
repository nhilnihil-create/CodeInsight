//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define chmin(x,y) x = min(x, y)
#define chmax(x,y) x = max(x, y)
#define V vector
vector<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
vector<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

const int INF = 1001001001;

int main () {
    int n; cin >> n;
    V<P> v(n);
    rep(i, n) {
        int x, l; cin >> x >> l;
        v[i].first = x + l;
        v[i].second = x - l;
    }
    sort(all(v));
    int r = -INF;
    int ans = 0;
    rep(i, n) {
        if (r <= v[i].second) {
            ans++;
            r = v[i].first;
        }
    }
    cout << ans << endl;

    return 0;
}