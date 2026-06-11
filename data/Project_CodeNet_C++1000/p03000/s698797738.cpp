#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
	int n, x;
	cin >> n >> x;
	vector<int> l(n);
	rep(i, n) cin >> l[i];
	int cou = 1;
	int sum = 0;
	rep(i, n) {
		sum += l[i];
		if(sum <= x) {
			cou++;
		}
	}
	cout << cou << endl;
}
