#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {

    string S;
    cin >> S;

    ll Q;
    cin >> Q;

    ll T, F, count = 0;
    char tmp;
    string L, R, M;

    rep(i, Q) {
        cin >> T;
        if (T == 1) {
            count++;
        }
        else {
            cin >> F >> tmp;
            if (count % 2 == 0) {
                if (F == 1) {
                    L = tmp + L;
                }
                else {
                    R = R + tmp;
                }
            }
            else {
                if (F == 1) {
                    R = R + tmp;
                }
                else {
                    L = tmp + L;
                }
            }
        }
    }

    S = L + S + R;

    if (count % 2 != 0) {
        reverse(S.begin(), S.end());
    }

    cout << S;

    return 0;
}