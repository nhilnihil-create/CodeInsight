#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


const int MOD = 1E9 + 7;
void _main() {
        int n, m; cin >> n >> m;
        vector<int> broken(m); cin >> broken;
        sort(all(broken));
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
                if (binary_search(all(broken), i)) continue;
                dp[i] += dp[i - 1];
                if (i - 2 >= 0) dp[i] += dp[i - 2];
                dp[i] %= MOD;
        }

        cout << dp[n];
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
