#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        vector<int> b(n + 1);
        for (int j = 0; j < n; ++j) {
            int l = max(0, j - a[j]);
            int r = min(j + a[j] + 1, n);
            ++b[l];
            --b[r];
        }
        for (int j = 0; j < n; ++j) {
            b[j + 1] += b[j];
        }
        b.pop_back();
        if (a == b) {
            break;
        }
        a = b;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << '\n';   
    return 0;
}