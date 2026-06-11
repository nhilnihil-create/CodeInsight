#include <iostream>
using namespace std;

int main(void)
{
	int W, H, x, y, r;
	bool flg = false;

	cin >> W;
	cin >> H;
	cin >> x;
	cin >> y;
	cin >> r;

	if ((x+r) <= W) {
		if ((x-r) >= 0) {
			if ((y+r) <= H) {
				if ((y-r) >= 0) {
					cout << "Yes" << endl;
					flg = true;
				}
			}
		}
	}
	if (flg == false) {
		cout << "No" << endl;
	}
	return 0;
}

