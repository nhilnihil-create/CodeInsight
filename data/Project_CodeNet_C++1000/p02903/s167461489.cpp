#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    vector<vector<ll>> ans(H, vector<ll>(W,0));
    rep(h, 0, B){
        rep(w, 0, A){
            ans[h][w] = 0;
        }
        rep(w, A, W){
            ans[h][w] = 1;
        }
    }
    rep(h, B, H){
        rep(w, 0, A){
            ans[h][w] = 1;
        }
        rep(w, A, W){
            ans[h][w] = 0;
        }
    }

    rep(h, 0, H){
        rep(w, 0, W){
            cout << ans[h][w];
        }
        cout << endl;
    }
    return 0;
}