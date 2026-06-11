#include <bits/stdc++.h>
using namespace std;

int main() {
	int X, N;
	cin >> X >> N;
	set<int> p;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		p.insert(n);
	}
	for (int d = 0; d <= 105; ++d) {
		if (!p.count(X-d)) {
			cout << X-d << endl;
			return 0;
		}
		if (!p.count(X+d)) {
			cout << X+d << endl;
			return 0;
		}
	}

}