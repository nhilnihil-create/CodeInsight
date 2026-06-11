#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> p(m);
    rep(i, m) cin >> p[i].first >> p[i].second;
    rep(x, 1000) {
        string s = to_string(x);
        vector<int> d;
        rep(i, s.size()) d.push_back(s[i]-'0');
        if (d.size() != n) continue;
        bool ok = true;
        rep(i, m) {
            if (d[p[i].first - 1] != p[i].second) ok = false;
        }
        if (ok) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}