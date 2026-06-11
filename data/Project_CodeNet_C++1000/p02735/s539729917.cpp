#include <bits/stdc++.h>
using namespace std;
inline void read (int &x) {
	char ch = getchar(); x = 0;
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
} const int N = 105;
int h, w, f[N][N], k[N][N]; char ch[N];
#define judge(i, j, x, y) (k[i][j] == 1 && k[x][y] == 0)
signed main() {
	read (h), read (w);
	for (int i = 1; i <= h; ++i) {
		scanf ("%s", ch + 1);
		for (int j = 1; j <= w; ++j) k[i][j] = (ch[j] == '#');
	} for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j) {
			f[i][j] = 1e9;
			if (i == 1 && j == 1) f[i][j] = k[i][j];
			if (i - 1) f[i][j] = f[i - 1][j] + judge (i, j, i - 1, j);
			if (j - 1) f[i][j] = min (f[i][j], f[i][j - 1] + judge (i, j, i, j - 1));
		}
	return printf ("%d\n", f[h][w]), 0;
}