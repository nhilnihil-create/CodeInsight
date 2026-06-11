#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, b, n) for (int i = b; i < (b)+(n); i++)
using namespace std;
using ll = long long;

int main() {
	int x;
	cin >> x;
	int i = 1;
	while (1) {
		if (360 * i%x == 0) break;
		i++;
	}
	cout << 360 * i / x << endl;
	return 0;
}