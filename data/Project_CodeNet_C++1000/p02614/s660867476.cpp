#include <iostream>
using namespace std;

int main(){

    int H,W,K;  
    cin >> H >> W >> K;
    string c[H];

    for(int i = 0;i<H;i++){
        cin >> c[i];   
    }

    int count = 0;
    int ans = 0;
    for(int maski = 0;maski < (1<<H);maski++){
        for(int maskj = 0;maskj < (1<<W);maskj++){
            
        count = 0;

        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){

                if((((maski>>i)&1)==0)&&(((maskj>>j)&1)==0)&&(c[i][j]=='#')){
                    count++;
                }
            }
        }

        if(count == K) ans++;



    }
    }

    cout << ans << endl;
   

}