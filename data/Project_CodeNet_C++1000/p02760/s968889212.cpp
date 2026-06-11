#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    vector<vector<int>> A(3, vector<int> (3));
    rep(i, 3) rep(j, 3) cin >> A[i][j];
    
    int N;
    cin >> N;
    vector<int> b(N);
    rep(i, N) cin >> b[i];

    rep(i, 3) rep(j, 3) rep(k, N) {
        if (A[i][j] == b[k]) A[i][j] = 0;
    }

    bool ok = false;
    rep(i, 3) {
        if (A[i][0] == 0 && A[i][1] == 0 && A[i][2] == 0) ok = true;
        if (A[0][i] == 0 && A[1][i] == 0 && A[2][i] == 0) ok = true;
    }
    if (A[0][0] == 0 && A[1][1] == 0 && A[2][2] == 0) ok = true;
    if (A[0][2] == 0 && A[1][1] == 0 && A[2][0] == 0) ok = true;
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}