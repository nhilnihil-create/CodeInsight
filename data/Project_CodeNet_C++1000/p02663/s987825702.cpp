#include <iostream>

using namespace std;

int main() {

	int h1 = 0, m1 = 0, h2 = 0, m2 = 0, t = 0;
	cin >> h1 >> m1 >> h2 >> m2 >> t;
	cout << (h2 * 60 + m2) - (h1*60 + m1) - t;
	return 0;
}