#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int M, D, result = 0;
    cin >> M >> D;
    REP(i, M) {
        REP(j, D) {
            if ((j+1)/10 >= 2 && (j+1)%10 >= 2) {
                if (((j+1)/10) * ((j+1)%10) == (i+1)) {
                    result++;
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}
