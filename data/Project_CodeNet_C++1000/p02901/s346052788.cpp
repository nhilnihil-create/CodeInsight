#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int N, M;   cin >> N >> M;
    vector<ll> a(M);    vector<int> b(M);
    vector<vector<int> > c(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        for (int j = 0; j < b[i]; j++)
            cin >> c[i][j];
    }
    vector<vector<ll> > dp(1<<N, vector<ll>(M, 1e15));
    for (int i = 1; i < M; i++) 
        dp[0][i] = 0;
    for (int s = 0; s < (1<<N); s++) {
        int t = s;
        for (int i = 0; i < b[0]; i++) {
            if (((s>>(c[0][i]-1)) & 1) == 1)
                t = t ^ (1<<(c[0][i]-1));
        }
        if (t == 0)
            dp[s][0] = a[0];
    }

    for (int s = 1; s < (1<<N); s++) {
        for (int i = 0; i < M-1; i++) {
            int t = s;
            for (int k = 0; k < b[i+1]; k++) {
                if (((s>>(c[i+1][k]-1))&1) == 1)
                    t = t ^ (1<<(c[i+1][k]-1));
            }
            dp[s][i+1] = min(dp[s][i], dp[t][i] + a[i+1]);
        }
    }

    if (dp[(1<<N)-1][M-1] != 1e15)
        cout << dp[(1<<N) - 1][M-1] << endl;
    else 
        cout << -1 << endl;
    return 0;
}