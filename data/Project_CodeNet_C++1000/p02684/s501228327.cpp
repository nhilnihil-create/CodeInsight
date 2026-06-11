#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int mv[65][200005];

int main() {
    // 繰り返し二乗法
    int N;
    ll K;
    cin >> N >> K;
    rep(i, N) {
        int x;
        cin >> x;
        --x;
        mv[0][i] = x;
    }
    for (int i = 1; i < 65; i++) {
        for (int j = 0; j < 200005; j++) {
            mv[i][j] = mv[i-1][mv[i-1][j]];
        }
    }
    int ans = 0;
    int cur = 0;
    while (K > 0) {
        if (K&1) ans = mv[cur][ans];
        K >>= 1;
        cur++;
    }
    cout << ++ans << '\n';    
    return 0;
}
