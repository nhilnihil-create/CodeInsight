#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;

int main() {
	int n, m, a;
	cin >> n >> m;
	rep (i, m) {
		cin >> a;
		n -= a;
	}
	if (n < 0) n = -1;
	cout << n << endl;
	return 0;
}
