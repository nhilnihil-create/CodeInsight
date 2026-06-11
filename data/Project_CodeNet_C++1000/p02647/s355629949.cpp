#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 41; i++) {
        if (i == k) break;
        vector<int> imos(n, 0);
        for (int j = 0; j < n; j++) {
            int l = max(0, j - a[j]);
            int r = min(n - 1, j + a[j]);
            imos[l]++;
            imos[r + 1]--;
        }
        for (int j = 0; j < n; j++) imos[j + 1] += imos[j];
        a = imos;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ((i + 1 < n) ? ' ' : '\n');
    }
}