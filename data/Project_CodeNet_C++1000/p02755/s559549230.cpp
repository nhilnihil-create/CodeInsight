#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int x = (int) ceil(a / 0.08), y = (int) ceil(b / 0.1);

    for (int i = min(x, y), n = max(x, y); i <= n; i++)
        if (floor(0.08 * i) == a && floor(0.1 * i) == b) {
            cout << i << endl;
            return 0;
        }

    cout << -1 << endl;
}