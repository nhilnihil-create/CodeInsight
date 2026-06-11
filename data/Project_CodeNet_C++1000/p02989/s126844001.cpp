#include<bits/stdc++.h>

using namespace std;

int a[100005];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << a[n / 2 + 1] - a[n / 2] << '\n';
    return 0;
}

