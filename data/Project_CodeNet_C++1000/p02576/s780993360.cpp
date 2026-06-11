#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, t;
    cin >> n >> x >> t;
    int ans = t * ((n + x - 1) / x);
    cout << ans << '\n';
    return 0;
}