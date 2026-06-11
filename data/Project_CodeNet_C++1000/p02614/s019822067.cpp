//H and V
#include<bits/stdc++.h>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(void){
    // Your code here!
    int h,w,k;
    cin >> h >> w >> k;

    char c[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> c[i][j];
        }
    }
    

    
    int ans = 0;
    int black_num = 0;

    for(int i=0;i < (1 << h);i++){//赤にする行を選択
        for(int j=0;j < (1 << w);j++){//赤にする列を選択
            black_num = 0;
            for(int l=0;l<h;l++){
                for(int m=0;m<w;m++){
                    if((((i >> l) & 1) == 0) && (((j >> m) & 1) == 0) && (c[l][m] == '#')){
                        black_num++;
                    }
                }
            }
            if(black_num == k){
                ans++;
            }
        }
    }

    cout << ans << endl;
    
    
    
    
}