
#include<cstdio>

using namespace std;
char field[110][110];
static int N, M;
static char state[110][110];
static int dx[4] = { 0,1,0,-1 };
static int dy[4] = { 1,0,-1,0 };
static void dfs(int x, int y, char fruit) {
	state[x][y] = fruit;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&field[nx][ny] == fruit&&state[nx][ny] == '!') {
			dfs(nx, ny, fruit);
		}
	}
}
static void solve() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (state[i][j] == '!') {
				dfs(i, j, field[i][j]);
				ret++;
			}
		}
	}
	printf("%d\n", ret);
}
int main() {
	while (scanf("%d %d", &N, &M) != EOF) {
		getchar();
		if (N == 0 && M == 0)
			break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%c", &field[i][j]);
				state[i][j] = '!';
			}
			getchar();
		}
		solve();
	}
	return 0;
}