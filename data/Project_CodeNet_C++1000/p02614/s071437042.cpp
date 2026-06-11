#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> s(H);
    rep(i, H) cin >> s.at(i);

    int ans = 0;
    rep(i, 1 << H) rep(j, 1 << W){
        int count = 0;
        rep(m, H) rep(n, W){
            if(i >> m & 1) continue;
            if(j >> n & 1) continue;
            if(s.at(m).at(n) == '#') count++;
        }
        if(count == K) ans++;
    }
    cout << ans << endl;
    return 0;
}