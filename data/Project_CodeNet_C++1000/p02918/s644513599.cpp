#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int o(vector<int> y) {
	int a = 1;
	int x = y.at(0);
	for (int i = 1; i < y.size(); i++) {
		if (x != y.at(i)) a++;
		x = y.at(i);
	}
	return y.size()-a;
}

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> y(n);
	rep(i, n) {
		if (s.at(i) == 'L') y.at(i) = 0;
		else y.at(i) = 1;
	}
	for (int i = 1; i < n - 1; i++) {
		if (k == 0) { cout << o(y) << endl;	return 0;
		}
		if (y.at(i) != y.at(i - 1) && y.at(i) != y.at(i + 1)) { y.at(i) = y.at(i - 1); k--; }
	}
	int x = 0;
	int a = y.at(0);
	rep (i,y.size()) {
		if (k == 0) { cout << o(y) << endl;	return 0; }
		if (y.at(i) != a) {
			if (x != 0) {
				for (int j = x; j < i; j++) y.at(j) = y.at(x - 1);
				x = 0; k--;
			}
			else x = i;
		}
		a = y.at(i);
	}
	cout << y.size()-1 << endl;
}