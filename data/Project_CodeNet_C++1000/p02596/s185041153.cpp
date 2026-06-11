#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 1; i <= k; i++) {
        if (i == 1) a[i] = 7;
        else a[i] = 10 * a[i-1] + 7;
        a[i] %= k;
        if (a[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}