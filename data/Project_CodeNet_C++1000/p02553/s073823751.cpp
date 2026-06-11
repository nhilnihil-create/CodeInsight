#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long a[4];
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	cout << max(max(a[0] * a[2], a[0] * a[3]), max(a[1] * a[2], a[1] * a[3])) << endl;
	return 0;
}