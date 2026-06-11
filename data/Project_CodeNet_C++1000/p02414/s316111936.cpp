#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, n) for(int i = 0; i < n; i++)

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    ll a[n][m] = {};
    ll b[m][l] = {};
    ll c[n][l] = {};

    REP(i, n) {
        REP(j, m) cin >> a[i][j];
    }

    REP(i, m) {
        REP(j, l) cin >> b[i][j];
    }

    REP(i, n) {
        REP(j, l) {
            REP(k, m) c[i][j] += a[i][k] * b[k][j];
        }
    }

    REP(i, n) {
        REP(j, l) {
            if (j) cout << " ";
            cout << c[i][j];
        }
        cout << endl;
    }

}