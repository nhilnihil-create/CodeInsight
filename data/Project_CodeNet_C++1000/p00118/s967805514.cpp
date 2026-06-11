#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i=0; i<(n); ++i)

int H, W, size;
char map[101][101];
int owner[101][101];
void dfs(int i, int j, int size) {
    char c = map[i][j];
    owner[i][j] = size;
    if(j+1<W && map[i][j+1]==c && owner[i][j+1]==-1) dfs(i, j+1, size);
    if(j>0 && map[i][j-1]==c && owner[i][j-1]==-1) dfs(i, j-1, size);
    if(i+1<H && map[i+1][j]==c && owner[i+1][j]==-1) dfs(i+1, j, size);
    if(i>0 && map[i-1][j]==c && owner[i-1][j]==-1) dfs(i-1, j, size);
}
int main() {
    while(cin >> H >> W && H!=0 && W!=0) {
        rep(i, H) {
            rep(j, W) {
                cin >> map[i][j];
                owner[i][j]=-1;
            }
        }
        bool isFinished = false;
        size = -1;
        while(isFinished==false) {
            isFinished = true;
            rep(i, H) {
                rep(j, W) {
                    if(owner[i][j]==-1) {
                        dfs(i, j, ++size);
                        isFinished = false;
                    }
                }
            }
        }
        cout << size+1 << endl;
        }
    return 0;
}