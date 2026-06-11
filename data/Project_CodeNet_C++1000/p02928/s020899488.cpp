#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll inv=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<i;j++){
            if(a[j]>a[i]) inv++;
        }
    }
    ll mi=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j) continue;
            if(a[i]<a[j]) mi++;
        }
    }
    ll ans=(k*(k-1)/2)%MOD;
    ans=(ans*mi)%MOD;
    ans+=(inv*k)%MOD;
    ans%=MOD;
    cout << ans << endl;
}
