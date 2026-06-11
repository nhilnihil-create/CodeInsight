#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a[100010];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int zero = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) zero++;
    }
    if (zero > 0) {
        cout << "0" << endl;
        return 0;
    }

    long long prod = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] <= 1000000000000000000 / prod) {
            prod *= a[i];
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << prod << endl;
}