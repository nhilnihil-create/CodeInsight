#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = a;
    while(1) {
        if(ans % b == 0) {
            break;
        }
        ans += a;
    }
    cout << ans << endl;
    return 0;
}
