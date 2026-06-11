#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    if (n == 0) {
        cout << x;
        return 0;
    }
    vector<bool> p(100,0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        p[a-1] = true;
    }
    int i = x;
    int j = x;
    while (true) {
        if (i > 0) {
            if (p[i-1] == true) {
                i -= 1;
            } else {
                cout << i;
                return 0;
            }
        } else {
            cout << i;
            return 0;
        }
        if (j <= 100) {
            if (p[j-1] == true) {
                j += 1;
            } else {
                cout << j;
                return 0;
            }
        } else {
            cout << j;
            return 0;
        }
    }
    cout << 0;
}
