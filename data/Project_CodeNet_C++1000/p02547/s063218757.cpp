#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    bool ok = false;
    for(int i = 0; i + 2 < n; ++i) {
        if (a[i] == b[i] && a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2]) {
            ok = true;
        }
    }
    if (ok) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}
