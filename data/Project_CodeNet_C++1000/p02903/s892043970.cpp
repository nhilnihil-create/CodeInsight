#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	vector<vector<int>> ans(h, vector<int>(w));
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < w; j++) {
			ans[i][j] = j < a ? 0 : 1;
		}
	}
	for (int i = b; i < h; i++) {
		for (int j = 0; j < w; j++) {
			ans[i][j] = j < a ? 1 : 0;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}