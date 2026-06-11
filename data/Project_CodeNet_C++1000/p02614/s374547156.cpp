#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> c(H);
    for(auto &e : c) cin >> e;
    int ans = 0;
    rep(S, 1 << H) rep(T, 1 << W) {
        bitset<20> bh(S), bw(T);
        int cnt = 0;
        rep(i, H) rep(j, W) {
            if(bh[i]|| bw[j]) continue;
            if(c[i][j] == '#') cnt++;
        }
        if(cnt == K) ans++;
    }
    cout << ans << '\n';
    return 0;
}
