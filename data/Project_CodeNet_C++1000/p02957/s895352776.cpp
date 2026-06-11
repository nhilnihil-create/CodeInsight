#include <iostream>
using namespace std;

typedef int64_t ll;
int main()
{
	int a, b;
	cin >> a >> b;
	int ans = -1;
	int pref = (a + b) / 2;
	if (abs(a - pref) == abs(b - pref)) {
		cout << pref;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}