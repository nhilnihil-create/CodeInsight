#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll>p(n);
    vector<double>num(n+1,0);
    for(ll i=0;i<n;i++){
        cin >> p[i];
        num[i]=(p[i]+1.0)/2.0;
    }
    vector<double>dp(n+1,0);
    for(ll i=0;i<n;i++){
        dp[i+1]=dp[i]+num[i];
    }
    double ans=0;
    for(ll i=0;i<=n-k;i++){
        double x=dp[i+k]-dp[i];
        ans=max(ans,x);
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
