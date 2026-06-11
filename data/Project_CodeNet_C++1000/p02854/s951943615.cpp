#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    int n;
    cin >> n;
    double a[n];
    ll sum = 0;
    vector<ll>dp(n);
    rep(i,n){
        cin >> a[i];
        sum+=a[i];
        dp[i] = sum;
    }
    ll ans = 1000000000000000000;
    rep(i,n){
        ll x = abs(dp[i]-(sum-dp[i]));
        ans = min(ans,x);
    }
    cout << ans << endl;

    return 0;
}
