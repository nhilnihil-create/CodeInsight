#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	cout << a / b << " " << a % b << " " << flush;
	cout << fixed << (double)a / b << endl;

	return 0;
}
