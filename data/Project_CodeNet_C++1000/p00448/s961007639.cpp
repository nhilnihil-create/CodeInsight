# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
constexpr int MOD = 1000000000 + 7;
constexpr int INF = 2000000000;
using namespace std;

int h, w;
int osenbei[10][10000];
int ans;
int flag[10];

int count() {
	int res = 0;
	for (int j = 0; j < w; j++) {
		int count1 = 0;
		for (int i = 0; i < h; i++) {
			if ((flag[i] && !osenbei[i][j]) || (!flag[i] && osenbei[i][j]))count1++;
		}
		if (count1 < h - count1) {
			res += h - count1;
		}
		else {
			res += count1;
		}
	}
	return res;
}

void calc(int hcount) {
	if (hcount == h) {
		int num = count();
		if (ans < num)ans = num;
		return;
	}

	flag[hcount] = 0;
	calc(hcount + 1);

	flag[hcount] = 1;
	calc(hcount + 1);
}

int main() {
	while (cin >> h >> w&&h&&w) {
		ans = 0;
		for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)cin >> osenbei[i][j];
		calc(0);
		cout << ans << endl;
	}
}