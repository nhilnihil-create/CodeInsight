#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	//double c = a * 12.5;
	//double d = (a+1)*12.5;
	int c, d;
	if (a%2 == 0) {
		c = a/2 * 25;
		d = c+12;
	} else {
		d = (a+1)/2 * 25;
		c = d-12;
		d--;
	}

	int e = b * 10;
	int f = (b+1)*10;
	bool found = false;
	for (int i = c; i <= d; i++) {
		if (i >= e && i < f) {
			cout << i << endl;
			found = true;
			break;
		}
	}
	if (!found)
		cout << -1 << endl;
	return 0;
}