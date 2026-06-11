#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h;
    cin >> h;

    vi a(h + 1);
    rep(i, 1, h + 1) { cin >> a[i]; }

    rep(i, 1, h + 1) {
        cout << "node " << i << ": key = " << a[i] << ", ";
        if (i / 2 > 0) { cout << "parent key = " << a[i / 2] << ", "; }
        if (2 * i <= h) { cout << "left key = " << a[2 * i] << ", "; }
        if (2 * i + 1 <= h) { cout << "right key = " << a[2 * i + 1] << ", "; } 
        cout << endl;
    }

    return 0;
}
