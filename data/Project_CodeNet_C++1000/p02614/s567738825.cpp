#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long h, w, k;
    cin >> h >> w >> k;

    vector<vector<char> > maze(h, vector<char>(w));
    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            cin >> maze[i][j];
        }
    }
    vector<vector<char> > maze0(h, vector<char>(w));
    maze0 = maze;

    vector<bool> write_y(h);
    vector<bool> write_x(w);

    long long ans = 0;
    for(long long bit_y = 0; bit_y < (1 << h); bit_y++){
        for(long long bit_x = 0; bit_x < (1 << w); bit_x++){

            for(long long mask_y = 0; mask_y < h; mask_y++){
                for(long long mask_x = 0; mask_x < w; mask_x++){
                    if(bit_y & (1 << mask_y)) write_y[mask_y] = true;
                    else write_y[mask_y] = false;

                    if(bit_x & (1 << mask_x)) write_x[mask_x] = true;
                    else write_x[mask_x] = false;
                }
            }
            maze = maze0;

            for(long long i = 0; i < h; i++){
                for(long long j = 0;j < w; j++){
                    if(write_y[i] == true || write_x[j] == true) maze[i][j] = 'r';
                }
            }

            long long cnt = 0;
            for(long long i = 0; i < h; i++){
                for(long long j = 0;j < w; j++){
                    if(maze[i][j] == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}