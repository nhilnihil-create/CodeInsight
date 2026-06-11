#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int a[3][3];
    bool masu[3][3];
    int n;
    rep(i, 3) rep(j, 3) {
        cin >> a[i][j];
        masu[i][j] = false;
    }
    cin >> n;
    rep(i, n) {
        int b;
        cin >> b;
        rep(j, 3) {
            rep(k, 3) {
                if (b == a[j][k])
                    masu[j][k] = true;
            }
        }
    }
    rep(i, 3) {
        if (masu[0][i] && masu[1][i] && masu[2][i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    rep(i, 3) {
        if (masu[i][0] && masu[i][1] && masu[i][2]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (masu[0][0] && masu[1][1] && masu[2][2]) {
        cout << "Yes" << endl;
        return 0;
    }
    if (masu[0][2] && masu[1][1] && masu[2][0]) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}