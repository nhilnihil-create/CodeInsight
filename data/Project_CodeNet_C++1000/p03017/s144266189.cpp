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

    ll N, A, B, C, D;

    cin >> N >> A >> B >> C >> D;

    string S;
    cin >> S;

    S = '#' + S + '#';

    bool ans = true;

    repl(i, A, C){
        if (S[i] == '#' && S[i + 1] == '#') {
            ans = false;
        }
    }
    repl(i, B, D) {
        if (S[i] == '#' && S[i + 1] == '#') {
            ans = false;
        }
    }

    if (A < B && C > D) {
        ans = false;
        repl(i, B - 1, D) {
            if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
                ans = true;
            }
        }

    }
    if (ans) {
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}