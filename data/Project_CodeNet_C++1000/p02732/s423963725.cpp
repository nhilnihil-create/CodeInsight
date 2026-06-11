#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>cnt(n,0);
    for(ll i=0;i<n;i++){
        cin >> a[i];
        cnt[a[i]-1]++;
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ans+=(cnt[i]*(cnt[i]-1))/2;
    }
    ll copy=ans;
    for(ll i=0;i<n;i++){
        copy-=(cnt[a[i]-1]*(cnt[a[i]-1]-1))/2;
        copy+=((cnt[a[i]-1]-2)*(cnt[a[i]-1]-1))/2;
        cout << copy << endl;
        copy=ans;
    }
}