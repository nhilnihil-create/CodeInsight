#include<iostream>
#include<string.h>
using namespace std;
int W, H;
int a[101][101];
int sum;
int n;


void bfs(int x, int y) {
	a[x][y] = 4;
	if (x > 1 && a[x - 1][y] == n) bfs(x - 1, y);
	if (x < H&&a[x + 1][y] == n) bfs(x + 1, y);
	if (y > 1 && a[x][y - 1] == n)bfs(x, y - 1);
	if (y < W&&a[x][y + 1] == n) bfs(x, y + 1);
}

int main()
{
	while (cin >> H >> W&&W != 0 && H != 0) {
		sum = 0;
		memset(a, 0, sizeof(a));
		char c;
		int x, y;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> c;
				if (c == '#') {
					a[i][j] = 1;
				}
				else if (c == '*') {
					a[i][j] = 2;
				}
				else if (c == '@') {
					a[i][j] = 3;
				}
			}
		}
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (a[i][j] != 4) {
					n = a[i][j];
					bfs(i, j);
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}

