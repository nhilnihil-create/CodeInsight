#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a;
        n -= a;
        if (n < 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << n << endl;
}