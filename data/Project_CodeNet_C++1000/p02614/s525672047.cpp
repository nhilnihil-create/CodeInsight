#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+5;

void solve(){
    char C[10][10];
    char COPY[10][10];
    int h, w, k;
    cin >> h >> w >> k;
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c; cin >> c;
            C[i][j] = c;
        }
    }
    for(int i = 0; i < (1 << h); i++)
    for(int j = 0; j < (1 << w); j++){
        for(int p = 0; p < h; p++){
            for(int q = 0; q < w; q++){
                COPY[p][q] = C[p][q];
            }
        }
        for(int k = 0; k < h; k++){
            if(i & (1 << k)){
                for(int p = 0; p < w; p++){
                    COPY[k][p] = '.';
                }
            }
        }
        for(int k = 0; k < w; k++){
            if(j & (1 << k)){
                for(int p = 0; p < h; p++){
                    COPY[p][k] = '.';
                }
            }
        }
        int curr = 0;
        for(int p = 0; p < h; p++){
            for(int q = 0; q < w; q++){
                if(COPY[p][q] == '#') curr++;
            }
        }
        if(curr == k) ans++;
    }
    cout << ans << "\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool multitest = false;
    //multitest = true;
    if(multitest){
        int t; cin >> t;
        while(t--)
            solve();
    }
    else
        solve();
}




