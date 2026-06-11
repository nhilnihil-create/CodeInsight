#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int n;
    cin >> n;
    vector<pair<string, Int>> v(n);
    for (Int i = 0; i < (Int)v.size(); i++) {
        cin >> v[i].fi >> v[i].se;
    }
    string s;
    cin >> s;
    Int res = 0;
    bool check = false;
    for (Int i = 0; i < n; i++) {
        if (check) {
            res += v[i].se;
        }
        if (v[i].fi == s) {
            check = true;
        }
    }
    dump(res);
    return 0;
}
