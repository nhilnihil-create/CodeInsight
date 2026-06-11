#include<iostream>

using namespace std;

int main(void) {
	int x = 0;
	int h = 0, m = 0, s = 0;
	cin >> x;
	if (x >= 3600) {
		h = (int)(x / 3600);
		m = (int)((x % 3600) / 60);
	}
	else {
		m = (int)(x / 60);
	}

	s = x % 60;

	cout << h << ":" << m << ":" << s << endl;

}