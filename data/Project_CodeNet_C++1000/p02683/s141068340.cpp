#include <bits/stdc++.h>
#define rep(i,n) for (unsigned int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

const double PI = acos(-1);
const int INF = 1001001001;

int main()
{

    int n,m,x; cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n) {
        cin >> c.at(i);
        rep(j,m) cin >> a.at(i).at(j);
    }

    int ans = INF;
    rep(s, 1<<n) {
        int cost = 0;
        vector<int> d(m);
        rep(i, n) {
            if(s>>i&1) {
                cost += c.at(i);
                rep(j,m) d.at(j) += a.at(i).at(j);
            }
        }
        bool ok = true;
        rep(j,m) if(d.at(j) < x) ok = false;
        if(ok) ans = min(ans, cost);
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

}
