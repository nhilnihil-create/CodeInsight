#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
#include <functional>
#include <map>
#include <string>
using namespace std;
int w, h;
char field[25][25];
bool used[25][25];
int vx[] = { 1, 0, -1, 0 };
int vy[] = { 0, 1, 0, -1 };

int dfs(int x,int y){
    
    int ret = 1;
    used[x][y] = true;

    for (int i = 0; i < 4; i++){
        int nx, ny;
        nx = x + vx[i]; ny = y + vy[i];
        if (nx != 0 && nx != w + 1 && ny != 0 && ny != h + 1 && field[nx][ny] != '#'&&
            !used[nx][ny]){
            ret += dfs(nx, ny);
        }
    }

    return ret;
}

int main(void){

    while (true){
        cin >> w >> h;
        if (w == 0 && h == 0)break;
        for (int i = 1; i <= w; i++){
            for (int j = 1; j <= h; j++){
                used[i][j] = false;
            }
        }
        int sx, sy;
        for (int i = 1; i <= h; i++){
            for (int j = 1; j <= w; j++){
                cin >> field[j][i];
                if (field[j][i] == '@'){
                    sx = j; sy = i;
                }
            }
        }

        int ans;
        ans = dfs(sx, sy);
        cout << ans << endl;
        
    }
    

}