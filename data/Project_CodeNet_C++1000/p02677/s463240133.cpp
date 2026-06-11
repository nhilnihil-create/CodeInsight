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
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v) cerr << #v << ":"; rep(i, v.size()) cerr << " " << v[i]; cerr << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const double pi = 3.14159265358979323846;

int main(){
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double L, S;
    L = 30 * h + m / 2.0;
    S = m * 6;
    double diff = abs(L - S);
    if (diff > 180) diff = 360 - diff;
    double ans = a * a + b * b - 2 * a * b * cos(diff / 180 * pi);
    ans = sqrt(ans);
    cout << fixed << setprecision(15) << ans << endl;
}
