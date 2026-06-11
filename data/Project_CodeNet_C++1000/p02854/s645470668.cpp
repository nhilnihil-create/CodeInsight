#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF (1<<18)



int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum_b = 0;

    rep(i,n){
        cin>>a[i];
        sum_b += a[i];
    }

    ll ans = sum_b;
    ll sum_f = 0;
    rep(i,n){
        sum_f += a[i];
        ans = min(ans, abs(sum_f - (sum_b - sum_f)));
    }

    cout << ans << endl;
    return 0;
}