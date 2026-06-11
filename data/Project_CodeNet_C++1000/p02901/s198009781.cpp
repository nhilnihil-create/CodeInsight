#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    int n, m;
    cin >> n >> m;
    V<int> a(m), b(m);
    V<V<int>> c(m, V<int>(n));
    rep(i,m) {
        cin >> a[i] >> b[i];
        rep(j,b[i]) {
            int d;
            cin >> d;
            c[i][d-1] = 1;
        }
    }

    V<V<int>> dp(m+1, V<int>(1<<n));
    rep(i,m+1)rep(j,(1<<n)) dp[i][j] = inf;
    dp[0][0] = 0;
    rep(i,m) {
        rep(j,(1<<n)) {
            int bit = j;
            rep(k,n) if(c[i][k]) bit |= (1<<k);
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][bit], dp[i][j] + a[i]);
        }
    }
    int ans = inf;
    Rep(i,m) {
        chmin(ans, dp[i][(1<<n)-1]);
    }
    if(ans == inf) ans = -1;
    cout << ans << endl;
}