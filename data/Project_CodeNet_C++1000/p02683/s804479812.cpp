#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> A(N,vector<int>(M));
    for (int i = 0; i < N; i++) {
        cin >> C.at(i);
        for (int j = 0; j < M; j++) {
            cin >> A.at(i).at(j);
        }
    }
    // 総当たりで最安値を探す
    int cost = 12 * 100000 + 1;

    // 組み合わせのループ
    for (int k = 0; k < (1 << N); k++) {
        bitset<12> b(k);
        int tmp = 0;
        vector<int> tmp_a(M);

        for (int i = 0; i < N; i++) {
            if (b[i] == 1) {
                tmp += C.at(i);
                for (int j = 0; j < M; j++) {
                    tmp_a.at(j) += A.at(i).at(j);
                }
            }
        }

        bool tf = true;
        for (int j = 0; j < M; j++) {
            if (tmp_a.at(j) < X) tf = false;
        }

        if (tf) {
            cost = min(cost, tmp);
        }
    }

    if (cost == 12 * 100000 + 1) cost = -1;
    cout << cost << endl;
}