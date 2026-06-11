#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long h, w;
    cin >> h >> w;

    char maze[h][w];

    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            cin >> maze[i][j];
        }
    }

    vector<vector<long long> > dp(h, vector<long long>(w, 1e9));

    if(maze[0][0] == '#'){
        dp[0][0] = 1;
    }
    else{
        dp[0][0] = 0;
    }

    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            long long nx, ny;
            nx = j;
            ny = i + 1;
            if(ny < h){
                if(maze[ny][nx] == '.'){
                    dp[ny][nx] = min(dp[ny][nx], dp[i][j]);
                }
                else{
                    if(maze[i][j] == '.'){
                        dp[ny][nx] = min(dp[ny][nx], dp[i][j]+1);
                    }
                    else{
                        dp[ny][nx] = min(dp[ny][nx], dp[i][j]);
                    }
                }
            }
            
            nx++;
            ny--;
            if(nx < w){
                if(maze[ny][nx] == '.'){
                    dp[ny][nx] = min(dp[ny][nx], dp[i][j]);
                }
                else{
                    if(maze[i][j] == '.'){
                        dp[ny][nx] = min(dp[ny][nx], dp[i][j]+1);
                    }
                    else{
                        dp[ny][nx] = min(dp[ny][nx], dp[i][j]);
                    }   
                }
            }
        }
    }

    cout << dp[h-1][w-1] << endl;
    return 0;
}