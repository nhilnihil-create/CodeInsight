#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), dp(1<<n, mod);
    vector<vector<int>> c(m);
    rep(i, m){
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        rep(j, b[i]){
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<int> key(m, 0);
    rep(i, m)rep(j, b[i])key[i] |= (1<<c[i][j]);
    dp[0] = 0;
    rep(bit, (1<<n)){
        rep(i, m){
            int next = bit | key[i];
            chmin(dp[next], dp[bit] + a[i]);
        }
    }
    cout << (dp[(1<<n)-1] == mod ? -1 : dp[(1<<n)-1]) << endl;
}