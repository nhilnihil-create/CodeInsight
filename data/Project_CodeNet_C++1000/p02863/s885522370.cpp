#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int dp1[3005][3005];
int dp2[3005][3005];

int main() {
    int n, t; cin >> n >> t;
    vint a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n)rep(j,3005) {
        chmax(dp1[i+1][j],dp1[i][j]);
        if (j-a[i] >= 0) chmax(dp1[i+1][j],dp1[i][j-a[i]]+b[i]);
    }
    rep(i,n)rep(j,3005) {
        chmax(dp2[i+1][j],dp2[i][j]);
        if (j-a[n-i-1] >= 0) chmax(dp2[i+1][j],dp2[i][j-a[n-i-1]]+b[n-i-1]);
    }
    int ans = 0;
    rep(i,n) {
        rep(j,t) ans = max(ans,dp1[i][j]+dp2[n-i-1][t-1-j]+b[i]);
    }

    cout << ans << endl;
}