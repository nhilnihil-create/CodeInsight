#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    int h, w, k;
    cin >> h >> w >> k;
    char c[h][w];
    rep(i,h){
        rep(j,w){
            cin >> c[i][j];
        }
    }
    int ans = 0;
    for(int r = 0; r < (1<<h); r++){// 行をYes/Noでフラグ立てる
        for(int C = 0; C < (1<<w); C++){// 列をフラグ立てる
            int black = 0;
            rep(i,h){
                rep(j,w){
                    // フラグが立っていないところが'#'なら黒
                    if(((r >> i) & 1)==0 && ((C >> j) & 1)==0 && c[i][j]=='#') black++;
                }
            }
            if(black == k) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
