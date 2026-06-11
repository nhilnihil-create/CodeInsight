#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, ans = 0;
    cin >> n >> d;
    for (int i = min(n, d + 1); i <= n;) {
        ans++;
        if (i + d >= n) break;
        i = min(n, i + 2 * d + 1);
    }
    cout << ans;
    return 0;
}

