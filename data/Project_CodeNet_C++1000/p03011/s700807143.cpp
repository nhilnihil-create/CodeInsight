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

int p, q, r, m;
int main() {
    cin >> p >> q >> r;
    m = max(max(p, q), r);
    cout << p + q + r - m << endl;
    return 0;
}
