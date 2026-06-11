#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if ((n-1) * (n-2) / 2 < k) {
        cout << -1 << endl;
    }
    else {
        int d = (n-1) * (n-2) / 2 - k;
        cout << n - 1 + d << endl;
        for (int i = 2; i <= n; ++i) {
            cout << 1 << " " << i << endl;
        }
        int cnt = 0;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                if (cnt == d) break;
                else {
                    cout << i+2 << " " << j+2 << endl;
                    cnt++;
                }
            }
            if (cnt == d) break;
        }
    }
}