#include <iostream>
#include <vector>
using namespace std;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	int n, m; cin >> n >> m;
	vector<bool> ac(n);
	vector<int> wa(n);
	int ans1 = 0;
	int ans2 = 0;
	rep(i, 0, m) {
		int p;
		string s;
		cin >> p >> s;
		--p;
		if (s == "AC") {
			if (!ac[p]) {
				++ans1;
				ans2 += wa[p];
				ac[p] = true;
			}
		}
		else {
			if (!ac[p]) ++wa[p];
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}
