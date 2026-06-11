#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define INF (int)1e9+7

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;

int main() {
    int ans = 0;
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    vector<vi> chm(H,vi(W,0));
    vector<vi> cha(H,vi(W,0));

    //(W方向の)障害物に当たらない長さを求める
    rep(i, H) {
        rep(j, W) {
            if(S[i][j] == '.') {
                chm[i][j]++;
                if(j > 0) chm[i][j] += chm[i][j-1];
            }
        }
        repr(j, W-1) {
            if(chm[i][j] > 0) chm[i][j] = max(chm[i][j], chm[i][j+1]);
        }
    }

    //(H方向の)障害物に当たらない長さを求める
    rep(j, W) {
        rep(i, H) {
            if(S[i][j] == '.') {
                cha[i][j]++;
                if(i > 0) cha[i][j] += cha[i-1][j];
            }
        }
        repr(i, H-1) {
            if(cha[i][j] > 0) cha[i][j] = max(cha[i][j], cha[i+1][j]);
        }
    }

    //W方向とH方向の障害物に当たらない長さを足す
    rep(i, H) {
        rep(j, W) {
            cha[i][j] += chm[i][j] - 1;
        }
    }

    //一番長いのが答え
    rep(i, H) {
        rep(j, W) {
            ans = max(ans, cha[i][j]);
        }
    }

    cout << ans << "\n";
    return 0;
}
