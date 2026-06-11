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

double expectation(int p);

int main() {
    int N, K, key, tmp = 0, MAX = 0;
    cin >> N >> K;
    vector<int>p(N);

    rep(i, N) {
        cin >> p[i];
        tmp += p[i];
        if (i + 1 > K) {
            tmp -= p[i - K];
        }
        if (MAX <= tmp) {
            key = i;
            MAX = max(MAX, tmp);
        }
    }

    double ans = 0;
    double sum = 0;
    for (int i = key - K + 1; i <= key; i++) {
        sum += expectation(p[i]);
    }
 
    cout << setprecision(15) << sum;

    return 0;
}

double expectation(int p) {
    double A = 0;
    for(int i = 1; i <= p; i++) {
        A += i;
    }
    A /= p;
    return A;
}