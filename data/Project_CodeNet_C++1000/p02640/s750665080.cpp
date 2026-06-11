#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x, y;
    cin >> x >> y;

    rep(i,100) {
        rep(j,100) {
            if ((2*i + 4 *j == y) && i + j == x) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;

}
