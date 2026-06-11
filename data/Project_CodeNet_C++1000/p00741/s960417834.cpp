#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define REP(i,n) FOR(i,0,n)

using namespace std;
vector <vector<int> > seamap, visit;

int dx[8] = { 0, 1, 1, 1, 0,-1,-1,-1};
int dy[8] = {-1,-1, 0, 1, 1, 1, 0,-1};
int nx, ny;

void bfs(int x, int y){
    queue <pair <int, int> > Q;
    visit[x][y] = 1;
    Q.push(pair<int,int>(x, y));
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        REP(i,8){
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if(seamap[nx][ny] && !visit[nx][ny]){
                visit[nx][ny] = 1;
                Q.push(pair<int,int>(nx, ny));
            }
        }
    }
}

int main(){
    int w,h;
    while(cin >> w >> h && !(w == 0 && h == 0)){
        int island = 0;
        seamap.resize(w + 2);
        REP(i,w + 2){
            seamap[i] = vector<int>(h + 2, 0);
        }
        visit = seamap;
        FOR(y,1,h + 1){
            FOR(x,1,w + 1){
                cin >> seamap[x][y];
            }
        }
       FOR(x,1,w + 1){
            FOR(y,1,h + 1){
                if(seamap[x][y] && !visit[x][y]){
                    island++;
                    bfs(x,y);
                }
            }
        }
        cout << island << endl;
    }
}