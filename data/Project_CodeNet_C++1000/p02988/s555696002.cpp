#include<bits/stdc++.h>

using namespace std;

int p[25], a[4];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 2; i < n; ++i) {
        for (int j = i - 1; j <= i + 1; ++j) a[j - i + 2] = p[j];
        sort(a + 1, a + 4);
        if (a[2] == p[i]) ans++;
    }
    cout << ans << '\n';
    return 0;
}
