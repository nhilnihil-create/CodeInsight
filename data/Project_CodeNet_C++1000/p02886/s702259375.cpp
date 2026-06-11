#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
           // cout << "i = " << i << " j = " << j <<"\n";
            ans += v[i] * v[j];
           // cout << ans << "\n";
        }
    }
    cout << ans << "\n";
}













