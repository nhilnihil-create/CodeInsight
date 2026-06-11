#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A.at(i);
    ll MOD = 1000000007;
    ll cnt = 0;
    rep(i,N) {
        rep(j,N) {
            if (i == j) continue;
            if (A[i] > A[j]) {
                if (i > j) {
                    cnt += (K - 1) * K / 2;
                    cnt %= MOD;
                } else { 
                    cnt += K * (K + 1) / 2;
                    cnt %= MOD;
                }
            }
        }
    }
    cout << cnt << endl;
}
