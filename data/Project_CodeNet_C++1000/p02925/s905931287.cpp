// 6/30 解き直し
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N-1));
    rep(i, N) rep(j, N-1) {
        cin >> A[i][j];
        A[i][j]--;
    }

    vector<int> b(N, 0);
    int res = 0;
    int matches = 0;

    // 貪欲に解いてみる。
    while (true) {
        // ある日
        int add = 0;  // その日の試合数
        vector<bool> match(N, false);

        // printf("day %d\n", res);

        rep(i, N) {
            if (match[i]) continue;
            if (b[i] >= N-1) continue;

            int opponent = A[i][b[i]];

            if (A[opponent][b[opponent]] == i && match[opponent] != true) {
                // 相手も次の相手が自分だったらマッチ成立
                b[i]++;
                b[opponent]++;
                add++;

                match[i] = true;
                match[opponent] = true;

                // printf("(i, j) = %d, %d\n", i, opponent);
            }
        }

        if (add == 0) {
            cout << -1 << endl;
            return 0;
        } else {
            matches += add;
            res += 1;

            if (matches == N * (N-1) / 2) break;
        }
    }

    cout << res << endl;
}