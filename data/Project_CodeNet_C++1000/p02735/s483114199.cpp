#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    } else {
        return 0;
    }
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    } else {
        return 0;
    }
}

const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

const ll INF = 1LL<<60;
int H, W;
vector<string> fi;

ll solve() {
    vector<vector<ll>> dp(H, vector<ll>(W, INF));
    if (fi[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int dir = 0; dir < 2; dir++) {
                int ni = i + dx[dir], nj = j + dy[dir];
                if (ni >= H || nj >= W) continue;
                int add = 0;
                if (fi[ni][nj] == '#' && fi[i][j] == '.') add = 1;
                chmin(dp[ni][nj], dp[i][j]+add);
            }
        }
    }
    return dp[H-1][W-1];
}

int main() {
    cin >> H >> W;
    fi.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> fi[i];
    }
    cout << solve() << endl;
}
