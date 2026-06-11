#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	bool d[3] = {true, true, true};
	d[a-1] = false;
	d[b-1] = false;
	for (int i = 0; i < 3; i++) {
		if (d[i]) {
			cout << i+1 << endl;
			return 0;
		}
	}

	return 0;
}