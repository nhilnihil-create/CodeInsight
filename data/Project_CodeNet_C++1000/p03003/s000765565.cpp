#include <vector>
#include <iostream>
using namespace std;
long long sum[2001][2001];
long long MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for (int i =0; i < N; i++) cin >> S[i];
    for (int j= 0; j < M;j ++) cin >> T[j];

    sum[0][0] = 1;
    for (int i = 0; i <= N; i++) for (int j = 0; j <= M; j++) {
        if (j-1 >= 0) (sum[i][j] += sum[i][j-1]) %= MOD;
        if (i-1 >= 0) (sum[i][j] += sum[i-1][j]) %= MOD;
        if (j-1 >= 0 && i-1 >= 0) (sum[i][j] += MOD - sum[i-1][j-1]) %= MOD;

        if (i-1 >= 0 && j-1 >= 0 && S[i-1] == T[j-1]) {
            sum[i][j] += sum[i-1][j-1];
            sum[i][j] %= MOD;
        }
    }
    cout << sum[N][M] << endl;
}