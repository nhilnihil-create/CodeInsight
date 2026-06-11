#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long a[n];
    long long product = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << 0;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > 1000000000000000000 / product) {
            cout << -1;
            return 0;
        }
        product = product * a[i];
    }
    cout << product;
}
