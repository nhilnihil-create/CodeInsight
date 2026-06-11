#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n), b(n);
    rep(i, n)cin >> a[i] >> b[i];
    vector<vector<int>> dp1(n+1, vector<int>(t+1, 0));
    vector<vector<int>> dp2(n+1, vector<int>(t+1, 0));
    rep(i, n){
        rep(j, t+1){
            if(j >= a[i]) dp1[i+1][j] = max(dp1[i][j-a[i]] + b[i], dp1[i][j]);
            else dp1[i+1][j] = dp1[i][j];
        }
    }
    reverse(all(a)); reverse(all(b));
    rep(i, n){
        rep(j, t+1){
            if(j >= a[i]) dp2[i+1][j] = max(dp2[i][j-a[i]] + b[i], dp2[i][j]);
            else dp2[i+1][j] = dp2[i][j];
        }
    }
    reverse(all(dp2));
    reverse(all(a)); reverse(all(b));
    int ans = 0;
    rep(i, n){
        rep(j, t){
            ans = max(ans, dp1[i][j] + dp2[i+1][t-j-1] + b[i]);
        }
    }
    cout << ans << endl;
}
