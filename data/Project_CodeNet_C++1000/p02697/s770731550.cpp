#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    if (n % 2 == 1) {
        for (int i = 0; i < m; i++) {
            cout << i + 1 << " " << n - i << "\n";
        }
    } else {
        int m1 = (m + 1) / 2;
        int m2 = m - m1;
        for (int i = 0; i < m1; i++) {
            cout << i + 1 << " " << 2 * m1 - i << "\n";
        }
        for (int i = 0; i < m2; i++) {
            cout << 2 * m1 + i + 1 << " " << 2 * m1 + 2 * m2 + 1 - i << "\n";
        }
    }

    return 0;
}