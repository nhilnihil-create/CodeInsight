#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int H, W, K; cin >> H >> W >> K;
    vector<string> A(H);
    rep(i, H) cin >> A[i];
    int cnt = 0;
    int H2 = 1 << H, W2 = 1 << W;
    rep(i, H2) rep(j, W2) {
        int cntblack = 0;
        rep(h, H) rep(w, W) {
            if(A[h][w] == '#' && (((1 << h) & i) == 0) && (((1 << w) & j) == 0)) cntblack++;
        }
        if(cntblack == K) cnt++;
    }
    cout << cnt << endl;
    return 0;
}