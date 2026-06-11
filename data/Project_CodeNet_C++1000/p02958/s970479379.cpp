#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (size_t i = 0; i < n; i++) cin >> p[i];

    for (size_t i = 0; i < n-1; i++) {
        if (p[i] >= p[i+1]) break;
        if (i == n-2) {
            cout << "YES" << endl;
            return 0;
        }
    }

    bool ok = false;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i+1; j < n; j++) {
            swap(p[i], p[j]);
            for (size_t k = 0; k < n-1; k++) {
                if (p[k] >= p[k+1]) break;
                if (k == n-2) ok = true;
            }
            swap(p[i], p[j]);
        }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
