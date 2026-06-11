#include<iostream>

using namespace std;

int main() {
	int d, x, y, s = 0;
	while (cin >> d) {
		x = 600;
		s = 0;
		for (x -= d; x > 0; x -= d) {
			y = x * x;
			s += y * d;
		}
		cout << s << endl;
	}
	return 0;
}