#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int D; cin >> D;
    vector C(26, 0);
    rep(i,26) cin >> C.at(i);
    vector S(D, vector(26, 0));
    rep(i, D) rep(j, 26) cin >> S[i][j];
    vector T(D, 0);
    rep(i,D) cin >> T.at(i);
    vector last(26, 0);
    int sat = 0;
    rep(d, D) {
        int j = T[d] - 1;
        last[j] = d + 1;
        rep(i,26) sat -= (d + 1 - last[i]) * C[i];
        sat += S[d][j];
        cout << sat << endl;
    }
}