#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        auto a_old = a;
        vector<int> b(n);
        for (int j = 0; j < n; j++) {
            int rmin = max(0, j - a[j]);
            int rmax = min(n - 1, j + a[j]);
            b[rmin]++;
            if (rmax + 1 < n) {
                b[rmax + 1]--;
            }
        }
        for (int j = 0; j < n - 1; j++) {
            b[j + 1] += b[j];
        }
        for (int j = 0; j < n; j++) {
            a[j] = b[j];
        }
        if (a_old == a) {
            break;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n - 1] << endl;
    return 0;
}
