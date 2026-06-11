#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, r = 0; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] == a[i]) {
                continue;
            }
            for (int k = j - 1; k >= 0; k--) {
                if (a[k] == a[i] || a[k] == a[j]) {
                    continue;
                }
                if (a[i] + a[j] + a[k] > 2 * max(a[i], max(a[j], a[k]))) {
                    r++;
                }
            }
        }
    }
    cout << r << endl;
    return 0;
}

