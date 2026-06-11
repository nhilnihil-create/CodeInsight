#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W,K; cin >> H >> W >> K;
    vector<vector<char>> c(H,vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> c.at(i).at(j);
        }
    }
    int ans=0;
    for(int bit1=0; bit1<(1<<H); bit1++){
        for(int bit2=0; bit2<(1<<W); bit2++){
            int cnt=0;
            for(int i=0; i<H; i++){
                for(int j=0; j<W; j++){
                    if((bit1 & (1<<i)) && (bit2 & (1<<j))){
                        if(c.at(i).at(j)=='#') cnt++;
                    }
                }
            }
            if(cnt==K) ans++;
            
        }
    }
    cout << ans << endl;
}