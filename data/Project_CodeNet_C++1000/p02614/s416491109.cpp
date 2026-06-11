#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int H, W, K;
    cin >> H >> W >> K;
    char g[H][W], h[H][W];
    rep(i, H){
        rep(j, W){
            cin >> g[i][j];
        }
    }
    //条件を満たす場合の数の個数
    int ptn = 0;
    //各状態について見る
    for(int bith = 0; bith < (1<<H); bith++){
        for(int bitw = 0; bitw < (1<<W); bitw++){
            rep(i, H) rep(j, W) h[i][j] = g[i][j];

            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){
                    if(((bith >> i) & 1) || ((bitw >> j) & 1)) h[i][j] = 'r';
                }
            }
            int cnt = 0;
            rep(i, H) rep(j, W) if(h[i][j] == '#') cnt++;
            if(cnt == K) ptn++;
        }
    }
    cout << ptn << endl;
    return 0;
}