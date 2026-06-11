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

    ll N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;

    string T;
    cin >> T;

    ll score = 0;

    rep(i, N) {
        if (i < K) {
            if (T[i] == 'r') {
                score += P;
            }
            else if (T[i] == 's') {
                score += R;
            }
            else if (T[i] == 'p') {
                score += S;
            }
        }
        else {
            if (T[i] == 'r' && T[i- K] != 'r') {
                score += P;
            }
            else if (T[i] == 's' && T[i - K] != 's') {
                score += R;
            }
            else if (T[i] == 'p' && T[i - K] != 'p') {
                score += S;
            }
            else {
                T[i] = '.';
            }
        }
    }

    cout << score;

    return 0;
}