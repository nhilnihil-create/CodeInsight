#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int MAX_HW = 1000;
int n, h, w, rat, s[2], g[2], flag[MAX_HW+1][MAX_HW+1][2];
int town[MAX_HW+1][MAX_HW+1];
char town2[MAX_HW+1][MAX_HW+1];
queue <P> que;
P p;
void bfs(int sy, int sx){
	que.push(P(sy, sx));
	flag[sy][sx][0]=rat;
	while (que.size()){
	RE:
		p = que.front();
		que.pop();
		for (int i = -1; i <= 1; i++){
			for (int j = -1; j <= 1; j++){
				if (i == 0 || j == 0){
					if (town2[p.first + i][p.second + j] != 'X'&&flag[p.first + i][p.second + j][0] != rat&&p.first + i < h&&p.first + i >= 0 && p.second + j < w&&p.second + j >= 0) {
							flag[p.first+i][p.second+j][0] = rat;
							flag[p.first + i][p.second + j][1] = flag[p.first][p.second][1] + 1;
							if (town[p.first + i][p.second + j] == rat){
							if (rat == n) return;
							rat++;
							flag[p.first+i][p.second+j][0] = rat;
							while (que.size()){
								que.pop();
							}
							que.push(P(p.first + i, p.second + j));
							goto RE;
						}
						else{
						que.push(P(p.first + i, p.second + j));
						}
					}
				}
			}
		}
	}
}
int main(){
	cin >> h >> w >> n;
	rat = 1;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin >> town2[i][j];
			town[i][j] = town2[i][j] - 48;
			if (town2[i][j] == 'S'){
				s[0] = i;
				s[1] = j;
			}
			if (town[i][j] == n){
				g[0] = i;
				g[1] = j;
			}
		}
	}
	bfs(s[0], s[1]);
	cout << flag[g[0]][g[1]][1] << endl;
	return 0;
}