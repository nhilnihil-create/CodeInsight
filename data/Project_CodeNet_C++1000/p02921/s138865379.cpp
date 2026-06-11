#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int result = 0;
    REP(i, 3) {
        if (S[i] == T[i]) {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}
