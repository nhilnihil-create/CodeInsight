// 2015/07/03 Tazoe

#include <iostream>
using namespace std;

char F[102][102];

void DFS(int Y, int X, char C)
{
	if(F[Y][X]!=C)
		return;

	F[Y][X] = 0;

	DFS(Y-1, X, C);		// 上
	DFS(Y, X+1, C);		// 右
	DFS(Y+1, X, C);		// 下
	DFS(Y, X-1, C);		// 左
}

int main()
{
	while(true){
		int H, W;
		cin >> H >> W;

		if(H==0 && W==0)
			break;

		for(int y=0; y<=H+1; y++){
			for(int x=0; x<=W+1; x++){
				F[y][x] = 0;		// 初期化
			}
		}

		for(int y=1; y<=H; y++){
			for(int x=1; x<=W; x++){
				cin >> F[y][x];
			}
		}

		int cnt = 0;

		for(int y=1; y<=H; y++){
			for(int x=1; x<=W; x++){
				if(F[y][x]!=0){
					cnt++;
					DFS(y, x, F[y][x]);
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}