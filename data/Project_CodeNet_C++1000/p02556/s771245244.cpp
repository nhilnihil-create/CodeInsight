#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9 * 2;
int n, x, y, zx = 0, zm = INF, wx = -INF, wm = INF;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		zx = max(zx, x + y);
		zm = min(zm, x + y);
		wx = max(wx, x - y);
		wm = min(wm, x - y);
	}

	cout << max(zx - zm, wx - wm) << endl;
}
