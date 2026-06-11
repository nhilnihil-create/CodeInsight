#include <bits/stdc++.h>

using namespace std;

struct zahyou {
	int x;
	int y;
};

void makemap(vector<zahyou>& block, int i, int from,int way) {
	block[i].x = block[from].x;
	block[i].y = block[from].y;
	if(way == 0) {
		block[i].x--;
	}
	if(way == 1) {
		block[i].y--;
	}
	if(way == 2) {
		block[i].x++;
	}
	if(way == 3) {
		block[i].y++;
	}
}

int main(void) {
	int N;
	while(1) {
		cin >> N;
		if(N == 0) {
			break;
		}

		vector<zahyou> block(N);
		block[0].x = 0;
		block[0].y = 0;
		int from, way;
		for(int i = 0; i < N - 1; i++) {
			cin >> from >> way;
			makemap(block, i + 1, from, way);
		}

		int max_x = 0, min_x = 0, max_y = 0, min_y = 0;
		for(auto b : block) {
			if(b.x > max_x) {
				max_x = b.x;
			}
			if(b.x < min_x) {
				min_x = b.x;
			}
			if(b.y > max_y) {
				max_y = b.y;
			}
			if(b.y < min_y) {
				min_y = b.y;
			}
		}

		int H, W;
		H = max_y - min_y + 1;
		W = max_x - min_x + 1;
		cout << W << " " << H << endl;
	}
	return 0;
}