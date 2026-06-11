//Property Distribution
#include <iostream>
#include <cstring>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)

int W, H, ans;
char a[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


int dfs(int x, int y) {
	char cur = a[x][y];
	a[x][y] = 'X';
	fo(i, 4) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && xx < H && yy >= 0 && yy < W && a[xx][yy] == cur)
			dfs(xx, yy);
	}
}



void solve() {
	ans = 0;
	fo(i, H) cin >> a[i];
	fo(i, H) {
		fo(j, W) {
			if (a[i][j] != 'X') {
				dfs(i, j);
				ans++;
			}
		}
	}
}



int main() {
	//freopen("in.txt", "r", stdin);
	while (cin >> H >> W && W && H) {
		solve();
		cout << ans << endl;
	}
}