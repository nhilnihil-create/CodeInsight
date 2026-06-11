#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<int>> A(N, vector<int>(M));
    vector<int> c(N);

    for (int i = 0; i < N; i++) {
        cin >> c.at(i);
        for (int j = 0; j < M; j++) {
            cin >> A.at(i).at(j);
        }
    }
    int ans = 12345678;
    for (int bit = 0; bit < (1 << N); bit++) {
        int cost = 0;
        vector<int> level(M);
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                cost += c.at(i);
                for (int j = 0; j < M; j++) {
                    level.at(j) += A.at(i).at(j);   
                }
            }
        }
        bool ok = true;
        for (int j = 0; j < M; j++) {
            if (level.at(j) < X) ok = false;
        }
        if (ok) ans = min(ans, cost);
    }
    if (ans == 12345678) cout << -1 << endl;
    else cout << ans << endl;
    
}