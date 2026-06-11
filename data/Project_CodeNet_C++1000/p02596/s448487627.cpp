#include <iostream>
using namespace std;
using i64 = long long;

int main() {
    i64 k;
    i64 a = 0;
    i64 ans = 0;

    cin >> k;

    const i64 inf = 20000000;
    while (ans < inf) {
        ans++;
        a *= 10;
        a += 7;
        a %= k;
        if (a == 0) break;
    }

    if (ans >= inf) cout << -1 << endl;
    else cout << ans << endl;
}