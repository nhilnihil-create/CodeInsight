#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; ll k; cin >> n >> k;
    vector<vector<ll>> data(63,vector<ll>(n));
    for (int i = 0; i < n; i++) { cin >> data[0][i]; data[0][i]--; }
    for (int i = 0; i+1 < 63; i++) {
        for (int j = 0; j < n; j++) {
            data[i+1][j] = data[i][data[i][j]];
        }
    }
    int town = 0;
    for (int i = 62; i >= 0; i--) {
        if (k & 1ll<<i) town = data[i][town];
    }
    cout << town + 1 << endl;
    return 0;
}