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

ll a, b;

int main() {
    cin >> a >> b;
    ll c = a + b;
    if (c & 1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << c / 2 << endl;
    return 0;
}
