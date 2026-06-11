//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;

template<class T>
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


const int INF = 1e9;


void solve() {
    int N, M; cin >> N >> M;

    vector<pair<int, int>> key(M);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;

        int s = 0;
        for (int j = 0; j < b; j++) {
            int c; cin >> c; c--;
            s |= 1<<c; 
        }

        key[i] = make_pair(a, s);
    }

    vector<vector<int>> dp(M+1, vector<int>(1<<N, INF));

    dp[0][0] = 0;

    for (int i = 0; i < M; i++) {
        for (int s = 0; s < 1<<N; s++) {
            // not use
            chmin(dp[i+1][s], dp[i][s]);

            // use
            int cost = dp[i][s] + key[i].first;
            chmin(dp[i+1][s|key[i].second], cost);
        }
    }

    int ans;
    if (dp[M-1][(1<<N) - 1] == INF) ans = -1;
    else ans = dp[M-1][(1<<N) - 1];

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}