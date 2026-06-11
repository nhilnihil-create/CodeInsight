#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int a[N], pos[N];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    mp[0] = 1;
    int t = 0;
    ll ans = 0;
    ll s = 0;
    for(int i = n-1; i >= 0; i--) {
        if(i+k <= n) {
            mp[pos[i+k]]--;
        }
        t++;
        t%=k;
        s += a[i];
        s %= k;
        ll x = (s - t + k) % k;
        ans += mp[x];
        mp[(s-t+k)%k]++;
        pos[i] = (s-t+k)%k;
    }
    cout << ans << '\n';
    return 0;
}