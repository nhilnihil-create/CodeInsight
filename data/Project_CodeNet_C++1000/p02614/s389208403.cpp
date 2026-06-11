#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W,K;
    cin >> H >> W >> K;
    char c[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> c[i][j];
        }
    }
    int ans =0;
    for(int u = 0; u < (1<<(H+W)); u++){
        int w = u%(1<<W);
        int h = u/(1<<W);
        int count = 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(c[i][j] == '#' && !((1<<i)&h) && !((1<<j)&w)){
                    count++;
                }
            }
        }
        if(count == K) ans ++;
    }
    cout << ans << endl;
        
}