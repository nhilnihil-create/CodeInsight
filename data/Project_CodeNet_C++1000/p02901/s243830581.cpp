#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int N, M;
int a[1050], b[1050], c[1050][20];

void input() {
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        cin >> a[i] >> b[i];
        for(int j = 1; j <= b[i]; j++) cin >> c[i][j];
    }
}

void solve() {
    input();
    const int INF = 1e9;
    vector<int> dp(5000, INF);
    dp[0] = 0;
    for(int item = 1; item <= M; item++) {
        int now = 0;
        for(int j = 1; j <= b[item]; j++) {
            now |= (1 << (c[item][j] - 1));
        }
        for(int bits = 0; bits < (1 << N); bits++) {
            chmin(dp[bits | now], dp[bits] + a[item]);
        }
    }
    if(dp[(1 << N) - 1] == INF) dp[(1 << N) - 1] = -1;
    cout << dp[(1 << N) - 1] << endl;
    return;
}

int main() {
    solve();
    return 0;
}