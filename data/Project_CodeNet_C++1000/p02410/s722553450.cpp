#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m] = {};
    int b[m] = {};
    int c[n] = {};

    REP(i, n) {
        REP(j, m) cin >> a[i][j];
    }

    REP(i, m) cin >> b[i];

    REP(i, n) {
        REP(k, m) c[i] += a[i][k] * b[k];
        cout << c[i] << endl;
    }

}