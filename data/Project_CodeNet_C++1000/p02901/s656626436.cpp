#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
using PPI = pair<P, int>;
//ll const mod=998244353;
ll const mod = 1e9 + 7;
const ll MAX = 300000;
using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
using vd = vector<double>;
using vs = vector<string>;
using vp = vector<P>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvc = vector<vector<char>>;
using vvp = vector<vector<P>>;
using vvb = vector<vector<bool>>;
template <typename T>
bool chmax(T& a, const T b) { if (a < b) { a = b; return true; } return false; }
template <typename T>
bool chmin(T& a, const T b) { if (a > b) { a = b; return true; } return false; }


//////////////////////////////////////



int main() {
    int n, m;
    cin >> n >> m;
    vi a(m), c(m);
    rep(i, m) {
        int b;
        cin >> a[i] >> b;
        rep(j, b) {
            int t;
            cin >> t;
            t--;
            c[i] += (1 << t);
        }
    }
    vvi dp(1 << n, vi(m + 1, INF));
    dp[0][0] = 0;
    rep(i, 1 << n) {
        rep(j, m) {
            chmin(dp[i | c[j]][j + 1], dp[i][j] + a[j]);
            chmin(dp[i][j + 1], dp[i][j]);
        }
    }
    int ans = dp[(1 << n) - 1][m];
    if (ans == INF)cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}