#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n;
    cin >> n;

    int m = n + 1;
    vector<int> bad(m) , heroes(n);
    for (int i = 0 ;i < m ;i++)
        cin >> bad[i];

    long long ans = 0;
    for (int i = 0 ;i < n ;i++) {
        cin >> heroes[i];
        if (heroes[i] <= bad[i])
            ans += heroes[i];
        else {
            ans += bad[i];
            heroes[i] -= bad[i];
            ans += min(heroes[i] , bad[i + 1]);
            bad[i + 1] -= min(heroes[i] , bad[i + 1]);
        }
    }

    cout << ans;
}
