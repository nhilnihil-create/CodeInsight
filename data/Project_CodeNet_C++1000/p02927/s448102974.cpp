#include <iostream>

using namespace std;

int main()
{
	int m, d;
	cin >> m >> d;
	int ans = 0;
	int t;
	for (int i = 22; i <= d; i++) {
		if (i % 10 > 1 && i / 10 > 1) {
			t = (i % 10) * (i / 10);
			if (t <= m && t > 0) {
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}