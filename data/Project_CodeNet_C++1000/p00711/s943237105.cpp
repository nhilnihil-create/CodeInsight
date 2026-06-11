#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)
#define INF 1000000000


int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
	int W, H;
	while (cin >> W >> H, W || H) {
		int fy, fx;
		char field[21][21];
		bool visit[21][21] = {};
		REP(i, 0, H) REP(j, 0, W) {
			cin >> field[i][j];
			if (field[i][j] == '@') {
				fy = i;
				fx = j;
				visit[i][j] = true;
			}
		}

		queue<pair<int, int>> q;
		pair<int, int> pii;
		q.push(make_pair(fy, fx));
		visit[fy][fx] = true;

		while (!q.empty()) {
			pii = q.front();
			q.pop();

			REP(k, 0, 4) {
				int y = pii.first + dy[k];
				int x = pii.second + dx[k];
				if (y < 0 || x < 0 || y >= H || x >= W) continue;
				if (field[y][x] == '#' || visit[y][x]) continue;

				visit[y][x] = true;
				q.push(make_pair(y, x));
			}
		}

		int ans = 0;
		REP(i, 0, H) {
			REP(j, 0, W) {
				if (visit[i][j]) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}