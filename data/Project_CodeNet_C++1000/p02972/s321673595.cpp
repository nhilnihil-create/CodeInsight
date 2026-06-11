#include<bits/stdc++.h>

using namespace std;

int a[200005], ok[200005];

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
    vector < int > ans;
    for (int i = n; i >= 1; --i) {
        int sum = 0;
        for (int j = 2 * i; j <= n; j += i) {
            sum += ok[j];
        }
        sum %= 2;
        if (sum == a[i]) continue;
        ans.push_back(i);
        ok[i] = 1;
    }
    cout << ans.size() << '\n';
    for (auto key : ans) cout << key << " ";
    return 0;
}

