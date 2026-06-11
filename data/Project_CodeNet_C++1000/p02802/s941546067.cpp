#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; ++i)

int main() {

	int n, m, p;
	string s;
	cin >> n >> m;

	vector<bool> ac(n + 1);
	vector<int> wa(n + 1);
	int a = 0, b = 0;
	REP(i, m) {
		cin >> p >> s;
		if (s == "AC") {
			if (!ac[p]) {
				++a;
				b += wa[p];
			}
			ac[p] = true;
		}
		else {
			if (!ac[p]) wa[p]++;
		}
	}
	cout << a << " " << b;
	return 0;
}
