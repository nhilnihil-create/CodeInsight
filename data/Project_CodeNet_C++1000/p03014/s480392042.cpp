#include<cstdio>
const static int H_MAX = 2000;
const static int W_MAX = 2000;

bool grid[H_MAX + 2][W_MAX + 2];
unsigned vertical[H_MAX + 1][W_MAX + 1], horizontal[H_MAX + 1][W_MAX + 1];

int main(){
	int H, W;
	scanf("%d %d", &H, &W);
	for (int i = 0; i <= W + 1; ++i){
		grid[0][i] = grid[H + 1][i] = false;
	}
	for (int i = 1; i <= H; ++i){
		grid[i][0] = grid[i][W + 1] = false;
	}
	for (int i = 1; i <= H; ++i){
		scanf("\n");
		for (int j = 1; j <= W; ++j){
			char tmp;
			scanf("%c", &tmp);
			grid[i][j] = tmp == '.';
		}
	}
	for (int i = 1; i <= H; ++i){
		unsigned left;
		for (int j = 1; j <= W; ++j){
			if(grid[i][j] && !grid[i][j - 1]) left = j;
			if(grid[i][j] && !grid[i][j + 1]){
				for (int k = left; k <= j; ++k){
					horizontal[i][k] = j + 1 - left;
				}
			}
		}
	}
	for (int i = 1; i <= W; ++i){
		unsigned top;
		for (int j = 1; j <= H; ++j){
			if(grid[j][i] && !grid[j - 1][i]) top = j;
			if(grid[j][i] && !grid[j + 1][i]){				
				for (int k = top; k <= j; ++k){
					vertical[k][i] = j + 1 - top;
				}
			}
		}
	}
	unsigned ans = 0;
	for (int i = 1; i <= H; ++i){
		for (int j = 1; j <= W; ++j){
			if(grid[i][j] && ans < horizontal[i][j] + vertical[i][j] - 1) ans = horizontal[i][j] + vertical[i][j] - 1;
		}
	}
	printf("%u\n", ans);
	return 0;
}