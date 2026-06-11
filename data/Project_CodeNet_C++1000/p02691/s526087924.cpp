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
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll cnt=0;
    map<ll,ll> mp;
    for(ll i = 0; i < n; i++) {
        cnt+=mp[-(a[i]-i)];
        mp[a[i]+i]++;
    }
    cout << cnt << "\n";

    return 0;
}