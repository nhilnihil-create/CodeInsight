#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    if (A - B*2 < 0) {
        cout << 0 << endl;
    } else {
        cout << A - B*2 << endl;
    }
    return 0;
}
