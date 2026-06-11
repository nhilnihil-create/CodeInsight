#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    ll n;
    cin >> n;
    if (n%2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for (ll i = 10; i <= n; i *= 5) {
        ans += n/i;
    }
    cout << ans << endl;
    return 0;
}