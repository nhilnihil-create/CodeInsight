#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int n;
int a[20];
int x[20][20];
int y[20][20];

int counter(int x) {
    if (x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }

    int ans = 0;

    for (int bit = 0; bit < (1 << n); bit++) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (!(bit & (1 << (i-1)))) continue;
            for (int j = 1; j <= a[i]; j++) {
                if (((bit >> (x[i][j]-1)) & 1) ^ y[i][j]) ok = false;
            }
        }
        if(ok) ans = max(ans, counter(bit));
    }

    cout << ans << endl;
    return;
}

int main() {
    solve();
    return 0;
}