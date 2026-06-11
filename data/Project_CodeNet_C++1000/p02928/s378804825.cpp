#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n,k,p=1000000007;
    cin >> n >> k;
    vector<ll> a(n);for(int i=0;i<n;i++) cin >> a[i];  
    ll ans=0,ta=0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i]>a[j]) ta++;
        }
    }
    ans += k*ta; ans %= p;

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    vector<ll> b(n);
    for(int i = 1; i < n; i++) {
        if(a[i]==a[i-1]) b[i]=b[i-1];
        else b[i]=i;
    }

    ll x=k*(k-1)/2; x%=p;
    for(int i = 0; i < n; i++) {
        ll y=b[i];
        y *= x;
        y %= p;
        ans += y;
        ans %= p;
    }

    cout << ans << endl;
    return 0;
}
