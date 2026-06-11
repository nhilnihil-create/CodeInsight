#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = b - a + 1;
    ll cd = lcm(c, d);
    ll cnt = b / c + b / d - ((a - 1) / c + (a - 1) / d) - (b / cd - (a - 1) / cd);
    cout << ans - cnt << endl;
    
    return 0;
}
