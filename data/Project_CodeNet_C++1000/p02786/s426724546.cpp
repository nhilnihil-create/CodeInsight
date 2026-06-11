#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long h;
    cin >> h;

    long long ans = 0, num = 1;
    while (h >= 1) {
        ans += num;
        num *= 2;
        h /= 2;
    }
    cout << ans << endl;
}
