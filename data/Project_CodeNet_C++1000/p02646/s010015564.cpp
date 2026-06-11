#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	long long a, v, b, w, t;
	cin >> a >> v >> b >> w >> t;

	bool ok = abs(b - a) <= t * (v - w);
	cout << (ok ? "YES": "NO") << endl;
	return 0;
}
