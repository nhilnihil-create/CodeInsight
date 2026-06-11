#include <iostream>

using namespace std;

int a, b, c;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c;
	if (a < b && a < c && b < c) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}

	return 0;
}