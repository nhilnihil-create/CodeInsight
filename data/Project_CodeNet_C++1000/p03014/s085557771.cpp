#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "O3"
#define rep(i,a,n) for(long long i=a; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
const double EPS = 1e-9;
const ll powll = 1LL<<1;

/*
while(!frag && cin >> a >>b, a|b)
*/

int main(void){
    int h,w; cin >> h >> w;
    string s[h];
    rep(i,0,h){
        cin >> s[i];
    }
    int ue[h][w],sita[h][w], migi[h][w], hidari[h][w];
    rep(i,0,w){
        for(int j = h-1; j >= 0; j--){
            ue[j][i] = 0;
            if(s[j][i] == '.') {
                if(j == h-1) ue[j][i] = 1;
                else ue[j][i] = ue[j+1][i] + 1;
            }
        }
    }
    rep(i,0,w){
        rep(j,0,h){
            sita[j][i] = 0;
            if(s[j][i] == '.') {
                if(j == 0) sita[j][i] = 1;
                else sita[j][i] = sita[j-1][i] + 1;
            }
        }
    }
    rep(j,0,h){
        rep(i,0,w){
            migi[j][i] = 0;
            if(s[j][i] == '.'){
                if(i == 0) migi[j][i] = 1;
                else migi[j][i] = migi[j][i-1] + 1;
            }
        }
    }
    rep(j,0,h){
        for(int i = w-1; i >= 0; i--){
            hidari[j][i] = 0;
            if(s[j][i] == '.'){
                if(i == w-1) hidari[j][i] = 1;
                else hidari[j][i] = hidari[j][i+1] + 1;
            }
        }
    }

    int ans = 0;
    rep(i,0,h){
        rep(j,0,w){
            if(s[i][j] == '.'){
                ans = max(ans, ue[i][j]+sita[i][j]+migi[i][j]+hidari[i][j] -3);
            }
        }
    }
    cout << ans << "\n";
}