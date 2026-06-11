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

    ll a, b, c, d;
    cin >> a >> b >> c;
    d = c - a - b;

    if (d > 0 && d * d > 4 * a * b) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    
    return 0;
}