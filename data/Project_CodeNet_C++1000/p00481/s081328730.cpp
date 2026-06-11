#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> P;

int h, w, n;
char f[1000][1000];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

struct Ele {
	Ele(int a, double b, P c) : g(a), h(b), p(c) {}
	bool operator<(const Ele& right) const {
		return g + h > right.g + right.h;
	}
	int g;
	double h;
	P p;
};

double euclidean(P s, P g) {
	int y = s.first - g.first;
	int x = s.second - g.second;
	return sqrt(x*x + y*y);
}

int Astar(P s, P g) {
	bool used[1000][1000] = { false };
	priority_queue<Ele> que;
	que.push(Ele(0, euclidean(s, g), s));

	while (!que.empty()) {
		Ele t = que.top();
		que.pop();

		if (t.p == g)
			return t.g;
		if (used[t.p.first][t.p.second])
			continue;
		used[t.p.first][t.p.second] = true;

		for (int i = 0; i < 4; ++i) {
			int ny = t.p.first + dy[i];
			int nx = t.p.second + dx[i];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w || f[ny][nx] == 'X')
				continue;

			P np(ny, nx);
			que.push(Ele(t.g + 1, euclidean(np, g), np));
		}
	}

	return 0;
}

int main() {
	cin >> h >> w >> n;

	P fac[10];
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> f[i][j];
			if ('1' <= f[i][j] && f[i][j] <= '9')
				fac[f[i][j] - '0'] = P(i, j);
			else if (f[i][j] == 'S')
				fac[0] = P(i, j);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += Astar(fac[i], fac[i + 1]);
	}

	cout << ans << endl;

	return 0;
}