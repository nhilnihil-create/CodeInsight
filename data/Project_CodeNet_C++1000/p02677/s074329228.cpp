#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
static const double pi = 3.141592653589793;

void solve() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    int f = 6 * m;
    double t = 30 * h + m * 0.5;
    double th = t - f;
    if (th < 0) th = -th;
    if (th >180) th = 360 - th;
    cout << fixed << setprecision(10) <<  sqrt(a * a + b * b - 2 * a * b * cos(pi * th / 180)) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}