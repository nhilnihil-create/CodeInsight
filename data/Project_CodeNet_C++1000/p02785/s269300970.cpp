#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (size_t i = 0; i < n; i++) cin >> h[i];

    if (n <= k) {
        cout << 0 << endl;
        return 0;
    }

    sort(h.begin(), h.end(), greater<int>());
    long long ans = 0;
    for (size_t i = k; i < n; i++) ans += h[i];

    cout << ans << endl;
    return 0;
}
