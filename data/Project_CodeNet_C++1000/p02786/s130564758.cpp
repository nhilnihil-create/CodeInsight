#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    ll h;
    cin >> h;
    ll ans = 0;
    ll num = 1;
    while (h >= 1) {
        ans += num;
        h /= 2;
        num *= 2;
    }
    cout << ans << endl;
    return 0;
}
