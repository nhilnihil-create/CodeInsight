#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n, k;
    ll R, S, P;
    string t;
    cin >> n >> k >> R >> S >> P >> t;
    int r = 0, s = 0, p = 0;
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            if (t[i] == t[i - k]) t[i] = 'x';
        }
        if (t[i] == 'r') r++;
        if (t[i] == 's') s++;
        if (t[i] == 'p') p++;
    }
    cout << r * P + s * R + p * S << endl;
    return 0;
}