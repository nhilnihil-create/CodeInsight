#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    ll l=1;
    bool jud=false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]/=2;

        ll prevl=l;
        l=l/__gcd(l,a[i])*a[i];
        if(l/prevl != a[i]/__gcd(prevl,a[i])) jud=true;
    }
    for(int i = 0; i < n; i++) if((l/a[i])%2==0) jud=true;
    ll ans=(m/l+1)/2;
    if(jud) ans=0;
    cout << ans << "\n";

    return 0;
}