#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long h, w, a, b;
    cin >> h >> w >> a >> b;

    long long ans[h][w];

    for(long long y = 0; y < h; y++){
        for(long long x = 0; x < w; x++){
            if(y < b){
                if(x < a) ans[y][x] = 0;
                else ans[y][x] = 1;
            }
            else{
                if(x < a) ans[y][x] = 1;
                else ans[y][x] = 0;
            }
        }
    }

    for(long long y = 0; y < h; y++){
        for(long long x = 0; x < w; x++){
            printf("%lld", ans[y][x]);
        }
        printf("\n");
    }
    return 0;
}