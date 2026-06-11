#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    ll n; cin >> n;
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(ALL(a),greater<pair<ll,ll>>());

    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;i+j<n;j++){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]+a[i+j].first * (a[i+j].second - i));
            dp[i][j+1] = max(dp[i][j+1],dp[i][j]+a[i+j].first * (n-1-j - a[i+j].second));
        }
    }

    ll ans = 0;
    for(int i=0;i<=n;i++) ans = max(ans,dp[i][n-i]);
    cout << ans << endl;

    return 0;
}