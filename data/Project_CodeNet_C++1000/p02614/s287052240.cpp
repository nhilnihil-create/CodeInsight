#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W,K,ans=0;
    cin >> H >> W >> K;
    vector <vector<char>> c(H,vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> c.at(i).at(j);
        }
    }
    for (int bith = 0; bith < (1<<H); bith++){
        for (int bitw = 0; bitw < (1<<W); bitw++){
            int judge=0;
            for (int i = 0; i < H; i++){
                for (int j = 0; j < W; j++){
                    if((bith>>i) & 1 && (bitw>>j) & 1 && c[i][j] == '#') judge++;
                }                
            }
            if(judge==K) ans++;
        }
    }
    cout << ans << endl;
}