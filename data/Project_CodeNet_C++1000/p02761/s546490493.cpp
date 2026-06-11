#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector <int> s(m), c(m);
    for (int i = 0; i < m; i++)
        cin >> s[i] >> c[i];

    for (int i = 0; i <= 999; i++) {
        bool ok = 1;
        vector <int> e;
        int tt = i;
        if (i == 0) e.push_back(0);
        while (tt) {
            e.push_back(tt % 10);
            tt /= 10;
        }
        if (e.size() != n) continue;
        for (int j = 0; j < m; j++)
            if (e[e.size() - s[j]] != c[j]) ok = 0;
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}