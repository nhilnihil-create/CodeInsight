#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    ll n, p;
    string s;
    cin >> n >> p >> s;
    if(p == 2 || p == 5){
        ll ans = 0;
        rep(i, n) {
            if(ll(s[i] - '0') % p == 0){
                ans += i + 1;
            }
        }
        cout << ans << endl;
        return 0;
    }
    ll tens = 1, running = 0, ans = 0;
    map<ll, ll> counter;
    counter[0] = 1;
    for (ll i = n - 1; i >= 0; i--) {
        running += (s[i] - '0') * tens;
        running %= p;
        tens *= 10;
        tens %= p;
        ans += counter[running]++;
    }
    cout << ans << endl;
}