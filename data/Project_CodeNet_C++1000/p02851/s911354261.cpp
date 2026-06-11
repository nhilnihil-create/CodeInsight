#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto& ai:a) cin >> ai;

    vector<ll> b(n+1, 0);
    ll sum = 0;
    rep(i,n) {
        sum += a[i];
        b[i+1] = (sum-(i+1)) % k; 
    }

    unordered_map<ll, int> mp;
    ll ans = 0;
    rep(i,n+1) {
        if(i-k>=0) mp[b[i-k]]--;

        if(mp.count(b[i])) {
            ans += mp[b[i]];
            mp[b[i]]++;
        }
        else {
            mp[b[i]] = 1;
        }
    }

    cout << ans << endl;
    return 0;
}