#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c, k;
    int aa, bb, cc;
    cin >> a >> b >> c >> k;
    bool ans = false;
    rep(x, k+1) {
        aa = a << x;
        rep(y, (k+1-x)) {
            bb = b << y;
            rep(z, (k+1-x-y)) {
                cc = c << z;
                if ((aa < bb) && (bb < cc)) {
                    ans = true;
                }
            }
        }
    }

    if (ans == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}
