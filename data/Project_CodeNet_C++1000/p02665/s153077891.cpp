#include <iostream>
#define MAX 100000
#define ll unsigned long long
using namespace std;

int main() {
    ll n, a[MAX + 100], node[MAX + 100], res = 0;

    cin >> n;
    for (ll i = 0; i <= n; ++i) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << (a[0] == 1 ? 1: -1) << endl;
        return 0;
    }

    if (a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }

    node[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        if (a[i] > node[i - 1] * 2) {
            cout << -1 << endl;
            return 0;
        }

        node[i] = 2 * node[i-1] - a[i];
    }
    node[n] = 0;

    for (ll i = n+1; i-- > 0; ) {
        node[i-1] = node[i] + a[i] >= node[i-1] ? node[i-1] : node[i] + a[i];
        res += node[i] + a[i];
    }

    cout << res << endl;

}