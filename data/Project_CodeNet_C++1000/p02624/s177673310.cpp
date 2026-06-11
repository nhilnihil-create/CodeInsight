#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> cnt(n,0);
    for(ll i = 1; i <= n; i++) {
        ll d=i;
        while(d<=n) {
            cnt[d-1]++;
            d+=i;
        }
    }
    ll ans=0;
    for(ll i = 0; i < n; i++) {
        ans+=cnt[i]*(i+1);
    }
    cout << ans << "\n";

    return 0;
}