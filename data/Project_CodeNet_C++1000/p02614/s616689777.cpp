#include <iostream>
#include "string"
using namespace std;
int main() {
    int H,W,K;
    cin >> H >> W >> K;
    char map[H][W];
    for (int i = 0; i < H; ++i) {
        scanf("%s",map[i]);
    }

    int solutions = 0;
    for (int i = 0; i < (1 << H) - 1; ++i) {
        for (int j = 0; j < (1 << W) - 1; ++j) {
            int black = 0;
            for (int k = 0; k < H; ++k) {
                for (int l = 0; l < W; ++l) {
                    if( ( (i>>k)&1 )==0&&((j>>l)&1)==0&&map[k][l]=='#' ){
                        black++;
                    }
                }
            }
            if(black==K){
                solutions++;
            }
        }
    }
    cout << solutions;
    return 0;
}
