#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
ll per(ll n,ll x){
    ll ans = 1;
    rep(i,x)ans *= n-i;
    rep(i,x)ans /= i+1;
    ans %= 1000000000+7;
    return ans;
}
int main(){
    int n,k;
    cin >> n >> k;
    ll ans = 0;
    vector<ll>sum(n+1);
    sum[0] = 0;
    rep(i,n)sum[i+1] = sum[i] + i+1;
    for(int i = k;i <= n+1;i++){
        ll big = 0,sma = 0;
        if(n-i < 0)big = sum[n];
        else big = sum[n] - sum[n-i];

        sma = sum[i-1];
        //cout << i << ' ' << big << ' ' << sma << endl;
        ans += big - sma+1;
        ans %= 1000000000+7;
    }
    cout << ans << endl;
    return 0;
}