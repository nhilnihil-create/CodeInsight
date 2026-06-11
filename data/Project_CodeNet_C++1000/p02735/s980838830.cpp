#include <iostream> 
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int flip=0, h, w, mp[105][105];
char board[105][105];

bool inside(int r, int c){
    return r<=h && c<=w;
}
int dp(int r, int c){
    int sum =0;
    if(r==h && c==w){
        if(board[h][w]=='#'){
            sum=1;
        }
        return sum;
    }
    else if(mp[r][c]!=-1){
        return mp[r][c];
    }
    int result = INT_MAX;
    int dx[] ={0, 1};
    int dy[] ={1, 0};
    for(int i=0; i<2; i++){
        int nextRow = r + dx[i];
        int nextCol = c + dy[i];
        if(!inside(nextRow, nextCol))continue;
        else if(board[r][c]=='.')flip = dp(nextRow, nextCol);
        else if(board[r][c]=='#' && board[nextRow][nextCol]=='#')flip = dp(nextRow, nextCol);
        else if(board[r][c]=='#' && board[nextRow][nextCol]=='.')flip = dp(nextRow, nextCol) + 1;
        result = min(result, flip);
        mp[r][c]=result;
    }
    return result;
}

int main(){
memset(mp, -1, sizeof(mp));
    
    cin >> h >> w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> board[i][j];
        }
    }
    
    cout << dp(1, 1) << endl;
    return 0;
}