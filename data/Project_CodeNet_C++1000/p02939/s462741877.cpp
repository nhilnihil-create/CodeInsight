#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200100;

int n, d[N][4];
char s[N];

int main() {

	scanf("%s", s);

	int n = strlen(s);

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= 2; j++) {
			d[i][j] = -1;
		}
	}

	for (int i = 1; i <= 2 && i <= n; i++) {
		d[0][i] = 1;
	}

	int res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 2; j++) {
			if (d[i][j] == -1) {
				continue;
			}
			if (i + j == n) {
				res = max(res, d[i][j]);
			}
			for (int k = 1; k <= 2; k++) {
				int from = i + j;
				int to = from + k - 1;
				if (to >= n) {
					break;
				}
				if (k != j) {
					d[from][k] = max(d[from][k], d[i][j] + 1);
				} else if (j == 1 && s[i] != s[from]) {
					d[from][k] = max(d[from][k], d[i][j] + 1);
				} else if (j == 2 && s[i] != s[from] && s[from - 1] != s[to]) {
					d[from][k] = max(d[from][k], d[i][j] + 1);
				}
			}
		}
	}

	printf("%d\n", res);

	return 0;

}