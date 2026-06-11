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
    vector<int> s(m), c(m);
    rep(i, m) cin >> s.at(i) >> c.at(i);

    int ans = -1;
    rep(i, 1000) {
        string l = to_string(i);
        if (l.size() != n) continue;
        bool isOk = true;
        rep(j, m) {
            if(l.at(s.at(j) - 1) - '0' != c.at(j)) {
                isOk = false ;
            }
        }
        if (!isOk) continue;
        ans = i;
        break;
    }

    cout << ans << endl;

    return 0;
}
