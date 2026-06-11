#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> ds(n);
    for (int i = 0; i < n; i++) cin >>ds[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += ds[i] * ds[j];
        }
    }
    cout << ans << endl;
}
