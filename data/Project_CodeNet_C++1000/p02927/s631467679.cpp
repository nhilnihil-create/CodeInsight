#include <bits/stdc++.h>
typedef long long ll; 
const ll mod = 1e9+7;
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(n) scanf("%d", &n) 
using namespace std;

void solve() {
    int m, d; cin >> m >> d;
    int count = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= d; j++) {
            int d10 = j / 10;
            int d1 = j % 10;
            if ((d10 < 2) || (d1 < 2)) continue;
            if (d10 * d1 == i) count++;
        }
    }
    cout << count;
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}