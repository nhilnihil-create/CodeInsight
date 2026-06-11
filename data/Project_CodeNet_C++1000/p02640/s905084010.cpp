#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    int total = x * 4;
    if (total == y) {
        cout << "Yes";
        return 0;
    }
    for (int i = 0; i < x; i++) {
        total -= 2;
        if (total == y) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
