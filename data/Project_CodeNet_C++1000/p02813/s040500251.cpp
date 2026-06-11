#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n), r(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];
    iota (r.begin(), r.end(), 1);
    bool pf = true, qf = true;
    int a, b;
    for (int i = 1; pf || qf; i++) {
        if (p == r) {
            a = i;
            pf = false;
        }
        if (q == r) {
            b = i;
            qf = false;
        }
        next_permutation (r.begin(), r.end());
    }
    cout << abs(a-b) << endl;
}