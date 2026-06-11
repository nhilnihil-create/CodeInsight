#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <bitset>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using lint = long long;
using namespace std;

const int MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<int> D(N), C(N);
    rep(i, N) cin >> D[i];

    if (D[0] != 0) {
        cout << "0" << endl;
        return 0;
    }
    if (count(D.begin(), D.end(), 0) > 1) {
        cout << "0" << endl;
        return 0;
    }

    sort(D.begin(), D.end());

    lint res = 1;
    C[0] = 1;

    for (int i = 1; i < N; i++) {
        if (D[i] - D[i-1] > 1) {
            cout << "0" << endl;
            return 0;
        }
        ++C[D[i]];
    }

    for (int i = 1; i <= D[N-1]; i++) {
        rep(j, C[i]) {
            res *= C[i-1];
            res %= MOD;
        }
    }

    cout << res << endl;
    return 0;
}
