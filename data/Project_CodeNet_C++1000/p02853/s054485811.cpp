#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    auto f = [](int n) {
        return n == 3 ? 100000 : n == 2 ? 200000 : n == 1 ? 300000 : 0;
    };
    auto ans = f(x) + f(y);
    if (x == 1 && y == 1) ans += 400000;
    cout << ans << endl;
}
