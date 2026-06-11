#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, X, Y; cin >> N >> X >> Y;
    X--, Y--;
    vector V(N,0);
    for (int i = 0; i < N; i ++) {
        for (int j = i + 1; j < N; j++) {
            int step = min({j-i, abs(X-i) + 1 + abs(Y-j), abs(X-j) + 1 + abs(Y-i)});
            V[step]++;
        }
    }
    for (int i = 1; i < N; i++) cout << V[i] << endl;
}
