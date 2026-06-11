#include<iostream>
using namespace std;
int ans;
char room[22][22] = { '0' };

void judge(int x, int y) {
	ans++;
	room[x][y] = '#';
	if (room[x - 1][y] != '#') {
		judge(x - 1, y);
	}
	if (room[x + 1][y] != '#') {
		judge(x + 1, y);
	}
	if (room[x][y - 1] != '#') {
		judge(x, y - 1);
	}
	if (room[x][y + 1] != '#') {
		judge(x, y + 1);
	}
	return;
}

int main(void) {
	while (1) {
		int w, h, human_x, human_y;
		for (int i = 0; i <= 22; i++) {
			for (int j = 0; j <= 22; j++) {
				room[j][i] = { '#' };
			}
		}
		cin >> w >> h;
		if (w == 0) return 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> room[j][i];
				if (room[j][i] == '@') {
					human_x = j;
					human_y = i;
				}
			}
		}
		ans = 0;
		judge(human_x, human_y);

		cout << ans << endl;
	}

}