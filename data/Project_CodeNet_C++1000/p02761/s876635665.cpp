#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122



int main() {
    int n, m;
    cin >> n >> m;
    int s[m], c[m];
    rep(i, 0, m) {
        cin >> s[i] >> c[i];
        s[i]--;
    }
    rep(i, 0, 1000) {
        string x = to_string(i);
        if ((int)x.size() != n) continue;
        bool ok = true;
        rep(i, 0, m) {
            if (x[s[i]] - '0' != c[i]) ok = false;
        }
        if (ok) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
