#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	rep(i, n - 1) {
		int x;
		cin >> x;
		a[x]++;
	}
	rep(i, n) cout << a[i + 1] << endl;
	return 0;
}
