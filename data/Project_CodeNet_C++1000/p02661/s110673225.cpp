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
    int n;
    cin >> n;
    vec<pii> p(n);
    cin >> p;

    vec<int> a, b;
    for (int i = 0; i < n; ++i) {
        a.pb(p[i].x);
        b.pb(p[i].y);
    }

    sort(all(a));
    sort(all(b));

    if (n % 2 == 0) {
        double x = ((double)a[n / 2] + a[n / 2 - 1]) / 2;
        double y = ((double)b[n / 2] + b[n / 2 - 1]) / 2;
        int res = (int)((y - x) * 2) + 1;
        cout << res << endl;
    }
    else {
        cout << b[n / 2] - a[n / 2] + 1 << endl;
    }
}