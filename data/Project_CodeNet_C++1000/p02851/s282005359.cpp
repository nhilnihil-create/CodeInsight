#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

ll a[N], cum[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cum[i] = cum[i - 1] + a[i];
    map<int, ll> mp;
    ll ans = 0;
    mp[0] = 1;
    for(int i = 1; i <= min(k - 1, n); i++){
        ans += mp[((cum[i] - i) % k + k) % k];
        mp[((cum[i] - i) % k + k) % k]++;
    }
    for(int i = k; i <= n; i++){
        mp[((cum[i - k] - (i - k)) % k + k) % k]--;
        ans += mp[((cum[i] - i) % k + k) % k];
        mp[((cum[i] - i) % k + k) % k]++;
    }
    cout << ans;

    return 0;
}
