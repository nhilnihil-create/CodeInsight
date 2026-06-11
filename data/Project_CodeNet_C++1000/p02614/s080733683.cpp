#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    long long h, w, k;
    cin >> h >> w >> k;

    char c[h][w];
    char c2[h][w];

    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            cin >> c[i][j];
            c2[i][j] = c[i][j];
        }
    }

    long long ans = 0;
    for(long long bit_y = 0; bit_y < (1 << h); bit_y++){
        for(long long bit_x = 0; bit_x < (1 << w); bit_x++){
            
            for(long long mask_y = 0; mask_y < h; mask_y++){
                for(long long mask_x = 0; mask_x < w; mask_x++){
                    if(bit_y & (1 << mask_y) || bit_x & (1 << mask_x)){
                        c[mask_y][mask_x] = 'R';
                    }
                }
            }

            long long cnt = 0;

            for(long long i = 0; i < h; i++){
                for(long long j = 0; j < w; j++){
                    if(c[i][j] == '#') cnt++;
                    c[i][j] = c2[i][j];
                }
            }
            
            if(cnt == k) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}