#include <bits/stdc++.h>
using namespace std;

int n, kk, c;
char str[200005];
int work[2][200005];
int pw[2] = {0};

int main () {
	cin >> n >> kk >> c >> str;
	int rem = -1000000000;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'x')
			continue;
		if (i-rem > c) {
			work[0][++pw[0]] = i;
			rem = i;
		}
	}
	if (pw[0] > kk)
		return 0;
	pw[1] = pw[0];
	rem = 1000000000;
	for (int i = n-1; i >= 0; --i) {
		if (str[i] == 'x')
			continue;
		if (rem-i > c) {
			work[1][pw[1]--] = i;
			rem = i;
		}
	}
	for (int i = 1; i <= pw[0]; ++i)
		if (work[0][i] == work[1][i])
			cout << work[0][i]+1 << endl;
	return 0;
}