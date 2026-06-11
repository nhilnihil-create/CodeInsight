#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];
    map<ll, ll> mp;
    ll ans = 0;
    rep(i, 1, n+1){
        ans += mp[i-a[i]];
        mp[i+a[i]]++;
    }
    cout << ans << endl;
    return 0;
}