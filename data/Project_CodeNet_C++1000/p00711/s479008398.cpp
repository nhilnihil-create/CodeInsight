#include<iostream>
#include<vector>
#include<algorithm>

#define REP(i,n) for(int i=0;i<(n);i++)

using namespace std;

char field[20][20];
int w, h;
int cnt = 0;

int dfs(int x, int y){
    field[x][y] = '#';
    cnt++;

    for(int dx=-1; dx<=1; dx++){
        for(int dy=-1; dy<=1; dy++){
            if(dx!=0 && dy!=0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if(0 <= nx && nx < w && 0 <= ny && ny < h && field[nx][ny] == '.') dfs(nx,ny);
        }
    }


}

int main(){
    while(cin >> w >> h){
        if(w==0 && h==0) break;
        char line[w];
        int start_x, start_y;
        REP(j,h){
            cin >> line;
            REP(i,w){
                if(line[i] == '@'){
                    start_x = i;
                    start_y = j;
                    field[i][j] = '.';
                }
                field[i][j] = line[i];
            }
        }
        cnt = 0;
        dfs(start_x, start_y);
        cout << cnt << endl;
    }
    return 0;
}