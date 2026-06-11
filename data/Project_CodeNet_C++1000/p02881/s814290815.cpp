#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const ll INF = ll(1e18);

int main(){
    ll n;
    cin >> n;
    ll ans = INF;
    for(ll i = 1; i * i <= n;i++){
        if(n % i == 0){
            ll j = n / i;
            ans = min(ans,i+j-2);
        }
    }
    cout << ans << endl;
}