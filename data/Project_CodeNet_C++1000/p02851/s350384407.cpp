#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main() {
    int n, k;cin >> n >> k;
    vector<ll> v(n), ruiseki;
    ruiseki.push_back(0);
    for(int i = 0;i < n;i++){
        cin >> v[i];
        ruiseki.push_back(ruiseki.back() + v[i]);
    }
    ll ans = 0;
    map<ll, int> mp;
    for(int i = 0;i < n + 1;i++){
        ans += mp[((ruiseki[i] - i) % k + k ) % k];
        mp[((ruiseki[i] - i) % k + k) %k]++;
        if(i >= k - 1){
            mp[((ruiseki[i - k + 1] - (i - k + 1)) % k + k) %k]--;
        }
    }
    cout<<ans<<endl;
    return 0;
}