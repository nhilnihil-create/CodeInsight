#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	int n; cin >> n;
	vector<int> a(n), b(n);
	rep(i, 0, n)
		cin >> a[i] >> b[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (n & 1) {
		cout << b[n / 2] - a[n / 2] + 1 << endl;
	}
	else {
		int l = a[n / 2 - 1] + a[n / 2];
		int r = b[n / 2 - 1] + b[n / 2];
		cout << r - l + 1 << endl;
	}
	return 0;
}