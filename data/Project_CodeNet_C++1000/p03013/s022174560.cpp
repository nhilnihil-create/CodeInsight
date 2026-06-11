#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, m, t;
int a[N];
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        a[t] = -1;
    }
    a[0] = 1;
    if (a[1] != -1) a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == -1) continue;
        if (a[i - 1] != -1) {
            a[i] = a[i - 1];
        }
        if (a[i - 2] != -1) {
            a[i] = (a[i] + a[i - 2]) % mod;
        }
    }
    cout << a[n] << endl;
    return 0;
}
