#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int H,N; cin >> H >> N;
    vector<int> A(N), B(N);
    rep(i,N) {
        cin >> A.at(i) >> B.at(i);
    }

    vector<ll> DP(H+1, 1LL<<62);
    DP[0] = 0;
    for (int i = 0; i<= H; i++) {
        if (DP[i] == 1LL<<62) continue;
        rep(j,N) {
            int n = i + A[j];
            if (n > H) n = H;
            DP[n] = min(DP[n], DP[i] + B[j]);
        }
    }
    cout << DP[H] << endl;
}
