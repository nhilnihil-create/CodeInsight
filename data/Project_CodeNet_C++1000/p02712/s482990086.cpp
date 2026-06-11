#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans;
int32_t main() {
    ans = 0;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        if (i % 3 != 0 && i % 5 != 0) ans += i;
    }
    cout << ans;
}