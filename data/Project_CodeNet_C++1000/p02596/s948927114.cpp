#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;

    int a[1000000];
    for (int i = 0; i < k; i++) a[i] = 0;
    a[0] = 7;
    if (k == 7 || k == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i < k; i++) {
        a[i] = (10 * a[i - 1] + 7) % k;
        if (a[i] == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
