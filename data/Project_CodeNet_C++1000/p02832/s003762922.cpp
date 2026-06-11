#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector <int> v (n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (v[i] == cur) {
            cur++;
        }
    }
    if (cur == 1) {
        cout << -1 << "\n";
    } else {
        cout << n - cur + 1 << "\n";
    }
}