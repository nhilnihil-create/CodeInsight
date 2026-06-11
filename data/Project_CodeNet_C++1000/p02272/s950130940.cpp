#include <bits/stdc++.h>
using namespace std;

int cnt(int n) {
    if (n <= 1) return 0;
    return n + cnt(n / 2) + cnt(n - n / 2);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        cout << v[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << "\n";
    cout << cnt(n) << "\n";

    return 0;
}