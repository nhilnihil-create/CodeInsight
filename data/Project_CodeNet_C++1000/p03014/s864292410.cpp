//ABC129D
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int h, w;
	cin >> h >> w;
	bool wall[h][w];
	pair<int, int> m[h][w];
	for (int y = 0; y < h; y++) {
		string s;
		cin >> s;
		int count = 0;
		int last_x = 0;
		for (int x = 0; x < s.size(); x++) {
			if (s[x] == '#') {
				wall[y][x] = true;
				for (int tmp = last_x; tmp < x; tmp++) {
					m[y][tmp].first = count;
				}
				m[y][x].first = 0;
				count = 0;
				last_x = x+1;
			} else {
				count++;
				wall[y][x] = false;
			}
		}
		for (int tmp = last_x; tmp < w; tmp++) {
			m[y][tmp].first = count;
		}
	}
	for (int x = 0; x < w; x++) {
		int count = 0;
		int last_y = 0;
		for (int y = 0; y < h; y++) {
			if (wall[y][x]) {
				for (int tmp = last_y; tmp < y; tmp++) {
					m[tmp][x].second = count;
				}
				m[y][x].second = 0;
				count = 0;
				last_y = y+1;
			} else {
				count++;
			}
		}
		for (int tmp = last_y; tmp < h; tmp++) {
			m[tmp][x].second = count;
		}
	}

	int ans = 0;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int tmp = m[y][x].first + m[y][x].second - 1;
			if (ans < tmp) {
				ans = tmp;
			}
		}
	}
	cout << ans << endl;
	return 0;
}