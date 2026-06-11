#include <iostream>
using namespace std;
 
int main() {
	int w, h, x, y, r;
	bool p;
	cin >> w >> h >> x >> y >> r;
	p = x >= r && y >= r && w - r >= x && h - r >= y;
	if(p) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}