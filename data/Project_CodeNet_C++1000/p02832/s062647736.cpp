#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) cin >> v[i];

    int cur = 1, br = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == cur) {
            cur++;
        } else {
            br++;
        }
    }
    if (cur == 1)
        cout << -1 << endl;
    else
        cout << br << endl;

    return 0;
}
