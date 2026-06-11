#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t a, b, c, d; cin >> a >> b >> c >> d;
    int64_t ans = b - a + 1; int64_t l = lcm(c, d);
    ans -= (b / c - a / c + (a % c == 0));
    ans -= (b / d - a / d + (a % d == 0));
    ans += (b / l - a / l + (a % l == 0));
    cout << ans << endl;
    return 0;
}