#include <iostream>

using namespace std;

int W, H;
int x, y;
char tile[20][20];
int checked[20][20];
int dfs(int x, int y){
    checked[x][y] = 1;
    bool dead = false;
    if((x==0 || tile[x-1][y] == '#' || checked[x-1][y] == 1) &&
    (x==W-1 || tile[x+1][y] == '#' || checked[x+1][y] == 1) &&
    (y==0 || tile[x][y-1] == '#' || checked[x][y-1] == 1) &&
    (y==H-1 || tile[x][y+1] == '#' || checked[x][y+1] == 1)) dead = true;
    if(dead){
        return 1;
    }
    int tmp=0;
    if(x>0 && tile[x-1][y] == '.' && checked[x-1][y] == 0) tmp += dfs(x-1, y);
    if(x<W-1 && tile[x+1][y] == '.' && checked[x+1][y] == 0) tmp += dfs(x+1, y);
    if(y>0 && tile[x][y-1] == '.' && checked[x][y-1] == 0) tmp += dfs(x, y-1);
    if(y<H-1&&tile[x][y+1] == '.' && checked[x][y+1] == 0) tmp += dfs(x, y+1);
    return 1+tmp;
}
int main(){
    char tmp;
    while(cin >> W >> H && W && H){
        for(int j=0; j<H; ++j){
            for(int i=0; i<W; ++i){
                checked[i][j] = 0;
                cin >> tmp;
                switch(tmp){
                    case '.':
                        tile[i][j] = '.';
                        break;
                    case '#':
                        tile[i][j] = '#';
                        break;
                    case '@':
                        tile[i][j] = '.';
                        x = i;
                        y = j;
                        break;
                }
            }
        }
        cout << dfs(x, y) << endl;
    }
    return 0;
}