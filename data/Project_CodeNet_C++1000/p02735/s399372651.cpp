#include<iostream>
#include<cstring>

using namespace std;

int H, W;
int grid[105][105], memo[105][105][2];

int findRoute(int row, int col, int black){
    if(memo[row][col][black] != -1) return memo[row][col][black];

    if(grid[row][col] == 1){
        if(row == H && col == W) return black;
        if(row == H) return memo[row][col][black] = findRoute(row, col+1, 0) + black;
        if(col == W) return memo[row][col][black] = findRoute(row+1, col, 0) + black;
        return memo[row][col][black] = min(findRoute(row+1, col, 0), findRoute(row, col+1, 0)) + black;
    }

    if(grid[row][col] == 0){
        if(row == H && col == W) return 0;
        if(row == H) return memo[row][col][black] = findRoute(row, col+1, 1) ;
        if(col == W) return memo[row][col][black] = findRoute(row+1, col, 1) ;
        return memo[row][col][black] = min(findRoute(row+1, col, 1), findRoute(row, col+1, 1)) ;
    }

    return 121;
}

int main(){
    memset(grid, 0, sizeof(grid));
    memset(memo, -1, sizeof(memo));
    cin >> H >> W;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            char c;
            cin >> c;
            if(c == '#') grid[i][j] = 1;
        }
    }

    cout << findRoute(1, 1, 1) << endl;
}