#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int64_t a, b, c;
	cin >> a >> b >> c;
	if (c - b - a > 0 && 4 * a * b < (c - b - a) * (c - b - a)) {
		puts("Yes");
	}
	else {
		puts("No");
	}
	return 0;
}