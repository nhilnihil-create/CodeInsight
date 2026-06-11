#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

#define INF (1e+9)
#define LLINF (1e+18)
#define LL long long

using namespace std;

typedef struct info{
	int nx;
	int ny;
	int cost;
	int target;
	info(int a,int b,int c,int d){
		nx = a;
		ny = b;
		cost = c;
		target = d;
	}
}info;

bool isNumChar(char c){
	if((0 <= c-48)&&(c-48 <= 9))return true;
	return false;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int W,H;
int N;

int sx[16] = {0};
int sy[16] = {0};

char field[1024][1024] = {""};
int record[1024][1024][12] = {0};
bool flag[16] = {false};

queue<info> que;


int ans;



int recordReset(){
	for(int i = 0;i < 1024;i++){
		for(int j = 0;j < 1024;j++){
			for(int k = 0;k < 12;k++){
				record[i][j][k] = INF;
			}
		}
	}
}

int bfs(){
	info now(0,0,0,0);
	info next(0,0,0,0);
	for(int i = 0;i < N;i++){
		next = info(sx[i],sy[i],0,i+1);
		que.push(next);
	}

	recordReset();
	while(!que.empty()){
		now = que.front();
		que.pop();
		if(!flag[now.target]){
			//printf("###(%d,%d):::cost<%d>:::target<%d>\n",now.nx,now.ny,now.cost,now.target);
			if(record[now.nx][now.ny][now.target] > now.cost){
				record[now.nx][now.ny][now.target] = now.cost;
				if((sx[now.target] == now.nx)&&(sy[now.target] == now.ny)){
					flag[now.target] = true;
					//printf("###target<%d> completed\n",now.target);
					ans += record[now.nx][now.ny][now.target];
				}
				else{
					switch(field[now.nx][now.ny]){
					case 'X':
						break;
					default:
						for(int i = 0;i < 4;i++){
							next = info(now.nx + dx[i],now.ny + dy[i],now.cost + 1,now.target);
							que.push(next);
						}
						break;
					}
				}
			}
		}
	}
}


int main (void){
	//while(true){
		scanf("%d%d",&H,&W);
		scanf("%d",&N);
		//if((W == 0)&&(H == 0))break;

		ans = 0;

		//Reset Field
		for(int i = 0;i < 1024;i++){
			for(int j = 0;j < 1024;j++){
				field[j][i] = 'X';
			}
		}

		//Reset Flag
		for(int i = 0;i < 16;i++){
			flag[i] = false;
		}

		//Reading Data
		for(int i = 1;i <= H;i++){
			scanf(" ");
			for(int j = 1;j <= W;j++){
				scanf("%c",&field[j][i]);
				if(isNumChar(field[j][i])){
					sx[field[j][i]-48] = j;
					sy[field[j][i]-48] = i;
					//printf("###<%d>(%d,%d)\n",field[j][i] - 48,sx[field[j][i] - 48],sy[field[j][i] - 48]);

				}
				else if(field[j][i] == 'S'){
					sx[0] = j;
					sy[0] = i;
					//printf("###<S>(%d,%d)\n",j,i);
				}
			}
		}

		//DBG
		/*for(int i = 0;i < N;i++){
			printf("<%d>(%d,%d)\n",i,sx[i],sy[i]);
		}*/

		bfs();

		printf("%d\n",ans);
	//}

	return 0;
}