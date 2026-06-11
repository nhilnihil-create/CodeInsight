#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,ans=0; cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    for(ll i=1; i<n; i++) a[i] += a[i-1];
    ans = a[n-1];
    for(ll i=0; i<n-1; i++) {
        ans = min(ans, abs(a[n-1] - 2*a[i]));
    }
    cout<<ans;
}