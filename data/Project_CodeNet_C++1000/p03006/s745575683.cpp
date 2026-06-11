#include <bits/stdc++.h>

using namespace std;
using pint = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    map<pint, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int p = x[i] - x[j], q = y[i] - y[j];
            mp[pint(p, q)]++;
            cnt = max(cnt, mp[pint(p, q)]);
        }
    }
    cout << n - cnt << endl;
    return 0;
}
