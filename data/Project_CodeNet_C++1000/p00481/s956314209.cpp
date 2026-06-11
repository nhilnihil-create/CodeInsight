#include <iostream>
#include <queue>
#include <map>
#define INF 10000000
using namespace std;

typedef pair<int, int> P;

int H, W, N;
int d[1000][1000];
char cell[1000][1000];
int si, sj, sum = 0;

void bfs(P start, int search){
	//4????????¨
	int vi[4] = {0, 0, -1, 1}, vj[4] = {-1, 1, 0, 0};

	int gi, gj;

	//???????????¢???INF?????????????????????????????´???????????§?¨??????????
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			d[i][j] = INF;
			if(cell[i][j] == search + '0'){
				gi = i;
				gj = j;
			}
		}
	}

	//start??????????????¢0????????????
	d[start.first][start.second] = 0;

	queue<P> que;
	que.push(start);

	while(!que.empty()){
		P p = que.front();
		que.pop();

		//?????´??§break
		if(p.first == gi && p.second == gj) break;

		//next(i, j)
		int ni, nj;

		//4?????????
		for(int i=0;i<4;i++){
			ni = p.first + vi[i];
			nj = p.second + vj[i];

			if(ni >= 0 && ni < H && nj >= 0 && nj < W && cell[ni][nj] != 'X' && d[ni][nj] == INF){
				que.push(P(ni, nj));
				d[ni][nj] = d[p.first][p.second] + 1;
			}
		}
	}

	sum += d[gi][gj];

	if(search != N)	bfs(P(gi, gj), search+1);
}

int main(){
	cin >> H >> W >> N;

	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> cell[i][j];
			if(cell[i][j] == 'S'){
				si = i;
				sj = j;
			}
		}
	}
	
	bfs(P(si, sj), 1);

	cout << sum << endl;
}