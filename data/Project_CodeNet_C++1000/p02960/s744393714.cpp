#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



const int mod = 1e9 + 7;
void _main() {
        string s; cin >> s;
        reverse(all(s));
        int n = s.size();
        vector<int> dp(13);
        dp[0] = 1;
        int p = 1;
        for (int i = 0; i < n; i++) {
                vector<int> new_dp(13);
                if (s[i] != '?') {
                        for (int rem = 0; rem < 13;rem++) {
                                (new_dp[(rem + (s[i] - '0') * p) % 13] += dp[rem]) %= mod;
                        }
                } else {
                        for (int dig = 0; dig < 10; dig++) {
                                for (int rem = 0; rem < 13; rem++) {
                                        (new_dp[(rem + dig * p) % 13] += dp[rem]) %= mod;
                                }
                        }
                }

                (p *= 10) %= 13;
                dp = new_dp;
        }

        cout << dp[5];
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}