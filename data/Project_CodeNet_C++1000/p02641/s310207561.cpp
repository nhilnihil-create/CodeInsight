#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

void run() {
    int x, n;
    cin >> x >> n;
    vector<bool> has(102);
    for (int i = 0; i <n; i++) {
        int t;
        cin >> t;
        has[t] = true;
    }
    for (int d = 0;; d++) {
        int l = x - d, r = x + d;
        if (l < 0 || !has[l]) {
            cout << l << '\n';
            return;
        }
        if (!has[r]) {
            cout << r <<'\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    run();
    return 0;
}
