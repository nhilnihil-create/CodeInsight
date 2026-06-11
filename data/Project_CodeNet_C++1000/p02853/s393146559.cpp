#include <bits/stdc++.h>
using namespace std;
int main () {
	int a = 0;
	int p[2];
	cin >> p[0] >> p[1];
	for (int i = 0; i < 2; i++) {
		int g[] = {300000, 200000, 100000};
		if (p[i] <= 3) a += g[p[i]-1];
	}
	if (a == 600000) a += 400000;
	cout << a << endl;
}