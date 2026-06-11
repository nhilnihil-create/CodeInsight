#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include<iomanip>
#include<limits>
#include<unordered_set> 
#include<cmath>
using namespace std;
//long long p = 998244353;
long long p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<pin,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define fcout cout << fixed << setprecision(15)
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) lower_bound(h.begin(),h.end(),val)-h.begin()
#define upper(h,val) upper_bound(h.begin(),h.end(),val)-h.begin()
int max_kai = 150000;
vel kai(max_kai, 1);
vel inv_kai;
int rui(int a, int n, int mod) {
    if (n == 0) { return 1 % mod; }
    int x = rui(a, n / 2, mod);
    x *= x; x %= mod;
    if (n % 2 == 1) { x *= a; x %= mod; }
    return x;
}
vel pa;
int root(int x) {
    if (pa[x] == -1) { return x; }
    int ans = root(pa[x]); pa[x] = ans;
    return ans;
}
void marge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) { pa[x] = y; }
}
int gcd(int x, int y) {
    if (x < y) { return gcd(y, x); }
    if (y == 0) { return x; }
    return gcd(y, x % y);
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
vel uni(vel x) {
    if (x.size() == 0) { return x; }
    sor(x);
    int n = x.size();
    vel ans(1, x[0]);
    for (int j = 1; j < n; j++) {
        if (x[j - 1] != x[j]) { ans.push_back(x[j]); }
    }
    x = ans;
    return x;
}
void pr(vel& v) {
    int n = v.size();
    if (n != 0) {
        cout << v[0];
        rep(i, n - 1) {
            cout << " " << v[i + 1];
        }
        cout << endl;
    }
}
signed main() {
    int n, k; cin >> n >> k;
    vel h(n);
    rep(i, n) { cin >> h[i]; }
    vel all = h; all.push_back(0); sor(all);
    rep(i, n) {
        h[i] = lower_bound(all.begin(), all.end(),h[i])-all.begin();
    }
    int inf = 1000000000;
    inf *= (n + n);
    V<vvel> dp(n+1, vvel(k + 2, vel(n + 1,inf)));//場所、回数、高さ
    dp[0][0][0] = 0;
    rep(i, n) {
        rep(j, k + 1) {
            rep(he, n + 1) {
                mmin(dp[i + 1][j][h[i]], dp[i][j][he] + all[h[i]] - min(all[h[i]], all[he]));
                mmin(dp[i + 1][j + 1][he], dp[i][j][he]);
            }
        }
    }
    int ans = inf;
    rep(j, k + 1) {
        rep(he, n + 1) {
            mmin(ans, dp[n][j][he]);
        }
    }
    cout << ans << endl;
    return 0;
}
