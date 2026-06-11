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

    ll N, K, S;

    cin >> N >> K >> S;

    vector<ll> A(N);
    ll count = 0;
    rep(i, N) {
        if (count < K) {
            cout << S << " ";
        }
        else if(S != pow(10, 9)){
            cout << S + 1 << " ";
        }
        else {
            cout << S - 1 << " ";
        }
        count++;
    }

    return 0;
}
