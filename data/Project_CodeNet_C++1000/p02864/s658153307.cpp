#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll INF = (1LL << 60);

int N, K;
vector<int> H;

void input(){
    cin >> N >> K;
    H.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> H[i];
}

int main(){
    input();

    vector<vector<ll>> DP(N, vector<ll>(N + 1, INF));
    DP[0][0] = 0;
    DP[0][1] = H[0];

    for (int i = 1; i < N; ++i){
        DP[i][0] = 0;
        DP[i][1] = H[i];
        for (int j = 2; j <= N; ++j){
            ll tmp = INF;
            for (int k = 0; k < i; ++k)
                tmp = min(tmp, DP[k][j - 1] + max(0, H[i] - H[k]));
            DP[i][j] = tmp;
        }
    }

    /*
    for (int i = 0; i < N; ++i){
        for (int j = 0; j <= N; ++j){
            if (DP[i][j] == INF) cout << "INF ";
            else cout << DP[i][j] << " ";
        }
        cout << endl;
    }
    */

    ll res = INF;
    for (int i = 0; i < N; ++i)
        res = min(res, DP[i][N - K]);

    cout << res << endl;

    return 0;
}