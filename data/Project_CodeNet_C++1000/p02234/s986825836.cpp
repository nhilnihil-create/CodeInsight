#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

struct mat {
    int row = -1;
    int col = -1;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<mat> M(N);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        M[i].row = a, M[i].col = b;
    }

    vector<vector<ll>> dp(N + 5, vector<ll>(N + 5, INF));
    rep(i, N + 5) { dp[i][i] = 0; }

    for (int w = 1; w < N; w++) {
        for (int i = 0; i < N; i++) {
            if (i + w >= N)
                continue;
            int j = i + w;
            for (int k = i; k < j; k++) {
                ll num_pro = M[i].row * M[k].col * M[j].col;
                dp[i][i + w] =
                    min(dp[i][i + w], dp[i][k] + dp[k + 1][i + w] + num_pro);
            }
        }
    }

    cout << dp[0][N - 1] << endl;
}
