#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define vint vector<int >
#define vll vector<ll >
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i,n) for (int i = 0; i < (n); ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int BIT[6] = {1,2,4,8,16,32};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int H, W, K, KNUM=0, ans=0;
    cin >> H >> W >> K;
    char C[H][W], COPY[H][W];
    REP(h,H){
        REP(w,W){
            cin >> C[h][w];
            if (C[h][w] == '#') KNUM++;
        }
    }
    int hbitMax = 1<<H;
    int wbitMax = 1<<W;

    for(int hbit = 0; hbit < hbitMax; hbit++){
        for(int wbit = 0; wbit < wbitMax; wbit++){
            // 初期化
            int KCNT = KNUM;
            REP(h,H){
                REP(w,W){
                    COPY[h][w] = C[h][w];
                }
            }
            REP(i,7){
                if((i<H) && (hbit & BIT[i])){
                    REP(w,W){
                        if(COPY[i][w] == '#'){
                            KCNT--;
                            COPY[i][w] = '$';
                            // cout << i << "," << w << "\n"; //
                        }
                    }
                }
                if((i<W) && (wbit & BIT[i])){
                    REP(h,H){
                        if(COPY[h][i] == '#'){
                            KCNT--;
                            COPY[h][i] = '$';
                            // cout << h << "," << i << "\n"; // 
                        }
                    }
                }
            }
            if(K == KCNT) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}