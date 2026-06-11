#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 400100;

int n, a, b, c, d;
char s[N];
bool can[4][N];

void bfs(int id, int start) {
	for (int i = 0; i < n; i++) {
		can[id][i] = false;
	}
	can[id][start] = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == '#') {
			continue;
		}
		if (i - 1 >= 0) {
			can[id][i] |= can[id][i - 1];
		}
		if (i - 2 >= 0) {
			can[id][i] |= can[id][i - 2];
		}
	}
}

int main() {

	scanf("%d %d %d %d %d %s", &n, &a, &b, &c, &d, s);

	a--;
	b--;
	c--;
	d--;

	bfs(0, a);
	bfs(1, b);

	for (int i = 0; i < n; i++) {
		can[2][i] = false;
		can[3][i] = false;
	}

	can[2][c] = true;
	can[3][d] = true;

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '#') {
			continue;
		}
		if (i + 1 < n) {
			can[2][i] |= can[2][i + 1];
			can[3][i] |= can[3][i + 1];
		}
		if (i + 2 < n) {
			can[2][i] |= can[2][i + 2];
			can[3][i] |= can[3][i + 2];
		}
	}

	if (!can[0][c] || !can[1][d]) {
		puts("No");
		exit(0);
	}

	if (d > c) {
		puts("Yes");
		exit(0);
	}

	for (int i = b + 1; i < n; i++) {
		if (i - 2 >= 0 && s[i] == '.' && s[i - 1] == '.' && s[i - 2] == '.' && can[1][i - 1] && can[0][i - 2] && can[2][i] && can[3][i - 1]) {
			puts("Yes");
			exit(0);
		}
	}

	puts("No");

	return 0;

}