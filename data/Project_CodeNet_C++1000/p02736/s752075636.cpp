#include <bits/stdc++.h>
using namespace std;

int lucas(int l, int r) {
	return !(~l & r);
}

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i) {
		char c; cin >> c;
		a[i] = c - '1';
	}
	{
		int cnt = 0;
		bool one = false;
		for(int i = 0; i < n; ++i) {
			if(a[i] == 1) {
				cnt += lucas(n - 1, i);
				cnt &= 1;
				one = true;
			}
		}
		if(cnt) {
			cout << 1 << '\n';
			return 0;
		}
		if(one) {
			cout << 0 << '\n';
			return 0;
		}
	}
	for(int i = 0; i < n; ++i) {
		a[i] >>= 1;
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] == 1) {
			cnt += lucas(n - 1, i);
			cnt &= 1;
		}
	}
	if(cnt) {
		cout << 2 << '\n';
		return 0;
	}
	cout << 0 << '\n';
	return 0;
}