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
int n;
int a[N], b[N];
ll res;

int main() {
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        ll c = min(b[i], a[i + 1]);
        b[i] -= c;
        res += c;
        c = min(b[i], a[i]);
        a[i] -= c;
        res += c;
    }
    cout << res << endl;

    return 0;
}
