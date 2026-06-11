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
 
const int MOD = 1e9 + 7, MAXN = 5e5 + 10, INF = 2e9 + 10, BASE = 37; 

void solve() {
    int n;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        if (v < u) swap(u, v);
        int cnt1 = u, cnt2 = n - v + 1;
        ans += (cnt1 * cnt2);
    }

    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
        tmp += i * (n - (i - 1));
    }

    cout << tmp - ans << endl;
}