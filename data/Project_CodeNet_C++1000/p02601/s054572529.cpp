#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    while (a >= b) {
        b *= 2;
        k--;
    }
    while (b >= c) {
        c *= 2;
        k--;
    }

    if (k >= 0)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;

    return 0;
}