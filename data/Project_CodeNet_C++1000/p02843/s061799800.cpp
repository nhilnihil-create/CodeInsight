#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n, ans; ans = 0;
    cin >> x;
    n = x / 100;
    if (100 * n <= x && x <= 100 * n + n * 5) {
        ans = 1;
    }
    cout << ans << endl;
    return 0;
}