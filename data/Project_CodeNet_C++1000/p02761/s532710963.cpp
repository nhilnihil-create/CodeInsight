#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> p(m);
    rep(i, m) cin >> p.at(i).first >> p.at(i).second;
    rep(x, 1000) {
        int keta = 1;
        int nx = x / 10;
        vector<int> d(1, x % 10);
        while(nx) {
            keta++;
            d.push_back(nx % 10);
            nx /= 10;
        }
        if (keta != n) continue;
        reverse(d.begin(), d.end());
        bool ok = true;
        rep(i, m) {
            if (d.at(p.at(i).first - 1) != p.at(i).second) ok = false;
        }
        if(ok) {
            cout << x << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
