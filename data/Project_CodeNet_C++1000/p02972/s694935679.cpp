#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n, 0);
    int m = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i > 0; --i) {
        int cnt = 0;
        for (int j = 1; j * i <= n; j++) {
            if (b[j * i - 1] == 1) ++cnt;
        }
        if (a[i - 1] != cnt % 2) {
            b[i - 1] = 1;
            ++m;
        }
    }
    cout << m << endl;
    for (int i = 0; i < n; i++) {
        if (b[i] == 1) cout << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}