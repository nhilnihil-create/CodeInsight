#include <bits/stdc++.h>
#define	rep(i,n) for (int i =0; i < (n); ++i)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	auto c = a;
	sort(a.begin(),a.end(),greater<int>());

	rep(i,n) {
		if (a[0] == c[i]) {
			cout << a[1] << endl;
		} else {
			cout << a[0] << endl;
		}
	}
	return 0;
}

