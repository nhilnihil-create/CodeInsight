#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    double A, B;
    cin >> A >> B;

    for (int i = 1; i < 1e8; i++) {
        if (floor(i * 0.08) == A && floor(i * 0.1) == B) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
