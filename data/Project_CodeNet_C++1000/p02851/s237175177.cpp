#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, k; cin >> n >> k;
    vector<ll> sum(n + 1);
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        sum[i] = (sum[i - 1] + a - 1) % k;
        sum[i] = (sum[i] + k) % k;
    }
    map<ll, ll> mp;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        if(i - k >= 0)mp[sum[i - k]]--;
        ans += mp[sum[i]];
        mp[sum[i]]++;
    }
    cout << ans << endl;
}