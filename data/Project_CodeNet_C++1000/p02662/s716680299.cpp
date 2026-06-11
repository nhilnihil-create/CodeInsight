#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
#define $(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define x first
#define y second
#define int long long
#define double long double
#define pii pair<int, int>
#define pb push_back
#define vec vector
#define beg begin
#define dbg(x) cout << #x << " = " << x << endl;
 
template<class T> ostream& operator<<(ostream &str, vector<T> &a) {
    for (auto &i : a) {
        str << i << " ";
    }
    return str;
}
 
template<class T> istream& operator>>(istream &str, vector<T> &a) {
    for (auto &i : a) {
        str >> i;
    }
    return str;
}
 
template<class T> ostream& operator<<(ostream &str, pair<T, T> &a) {
    str << a.first << " " << a.second;
    return str;
}
 
template<class T> istream& operator>>(istream &str, pair<T, T> &a) {
    str >> a.first >> a.second;
    return str;
}
 
void solve(); signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(6);
    solve();    
    return 0;
}
 
const int MOD = 998244353, MAXN = 5000 + 10, INF = 1e18 + 10, BASE = 37; 
 
void solve() {
    int n, s;
    cin >> n >> s;
    vec<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vec<vec<int>> dp(n + 2, vec<int>(s + 2));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i][j] = dp[i - 1][j] * 2 % MOD;
            if (j - a[i] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % MOD;
            }
        }
    }

    cout << dp[n][s] << endl;
}