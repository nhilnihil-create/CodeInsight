#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H);
    rep(i, H){
        cin >> S[i];
    }
    int ans[H][W];
    rep(i, H){
        rep(j, W){
            ans[i][j] = 0;
        }
    }
    int l = -1;
    int counter = 0;
    rep(i, H){
        rep(j, W){
            if(S[i][j] == '.'){
                if(counter == 0){
                    l = j;
                }
                counter++;
                if(j == W-1){
                    for (int k = W-1; k >= l; k--){
                        ans[i][k] += counter;
                    }
                }
            } else {
                if(counter != 0){
                    for (int k = j-1; k >= l; k--){
                        ans[i][k] += counter;
                    }
                }
                counter = 0;
            }
        }
        l = -1;
        counter = 0;
    }

    l = -1;
    counter = 0;
    rep(j, W){
        rep(i, H){
            if(S[i][j] == '.'){
                if(counter == 0){
                    l = i;
                }
                counter++;
                if(i == H-1){
                    for (int k = H-1; k >= l; k--){
                        ans[k][j] += counter;
                    }
                }
            } else {
                if(counter != 0){
                    for (int k = i-1; k >= l; k--){
                        ans[k][j] += counter;
                    }
                }
                counter = 0;
            }
        }
        l = -1;
        counter = 0;
    }

    int xx = 0;
    rep(i, H){
        rep(j, W){
            xx = max(xx, ans[i][j]);
            //cout << i << j << " " << ans[i][j] << endl;
        }
    }

    cout << xx-1 << endl;

    return 0;
}