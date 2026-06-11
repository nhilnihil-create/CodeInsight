#include <iostream>
using namespace std;

int main () {
	int w,h,x,y,r;
	cin >> w >> h >> x >> y >> r;
	if (r + x > w) {
		cout << "No" << endl;
	} else if (r > x) {
		cout << "No" << endl;
	} else if (r + y > h) {
		cout << "No" << endl;
	} else if (r > y) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
	return 0;
}
