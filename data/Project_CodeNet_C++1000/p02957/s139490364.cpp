#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b; cin >> a >> b;
	int m = (a + b);
	if (m & 1) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << m / 2 << '\n';
	}
}
