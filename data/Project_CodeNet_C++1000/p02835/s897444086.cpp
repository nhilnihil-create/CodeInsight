#include <iostream>

using namespace std;

int main()
{
	int x, y, z;

	cin >> x >> y >> z;

	if (x + y + z <= 21) {
		cout << "win" << endl;
	}
	else {
		cout << "bust" << endl;
	}
	return 0;
}