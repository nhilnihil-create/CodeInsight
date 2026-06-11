#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x.at(i);
    }
    int ans = 1e9;
    for (int p = 1; p <= 100; p++) {
        int po = 0;
        for (int i = 0; i < n; i++) {
            po += (x.at(i) - p) * (x.at(i) - p);
        }
        ans = min(ans, po);
    }
    cout << ans << endl;
    return 0;
}