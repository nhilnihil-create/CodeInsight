#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) c[i] = n-i;
        for (int i = 0; i < m; ++i) {
            int p, r; cin >> p >> r;
            rotate(c.begin(), c.begin()+p-1, c.begin()+p+r-1);
        }
        cout << c[0] << endl;
    }
}