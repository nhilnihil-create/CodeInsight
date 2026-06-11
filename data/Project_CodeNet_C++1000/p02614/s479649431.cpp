#include<bits/stdc++.h>
using namespace std;

int main(){
    int H, W, K;
    cin >> H >> W >> K;

    char C[H][W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> C[i][j];
        }
    }

    int ans=0;
    int count;

    for (int ibit = 0; ibit < (1 << H); ++ibit){
        for (int jbit = 0; jbit < (1 << W); ++jbit){
            count = 0;
            for(int i=0; i<H; i++){
                for(int j=0; j<W; j++){
                    if( ( ibit & (1<<i) ) || ( jbit & (1<<j) ) ) continue;
                    if( C[i][j]=='#' ) count++;
                }
            }
            if( count == K ) ans++;
        }    
    }

    cout << ans << endl;

    return 0;
}