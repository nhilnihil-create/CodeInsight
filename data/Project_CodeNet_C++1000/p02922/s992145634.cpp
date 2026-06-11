#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = 0, t = 1;
    while (t<b) {
        t += a-1;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
