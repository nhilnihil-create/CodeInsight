#include <iostream>
using namespace std;

int main() {

	int d, l, r;

	cin >> l >> r >> d;

	int x = l / d;
	int y = r / d;

	if(l % d == 0)
		cout << y - x + 1 << endl;
	else
		cout << y - x << endl;
}