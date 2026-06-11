#include <iostream>
#include <string>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long

using namespace std;

const int N = 1e6 + 10;

int n;
int a[N];
int b[N];

signed main() {
	int i;
	
	cin >> n;
	string s; cin >> s;
	rep(i, n) {
		a[i] = s[i] - '1';
	}
	
	rep(i, n) {
		b[i] = a[i] % 2;
	}
	
	int hoge = 0;
	rep(i, n) {
		if (((n - 1) & i) == i) { hoge ^= b[i]; }
	}
	if (hoge == 1) { cout << 1 << endl; return 0; }
	
	rep(i, n) { if (a[i] == 1) break; }
	if (i < n) { cout << 0 << endl; return 0; }
	
	rep(i, n) {
		b[i] = a[i];
	}
	hoge = 0;
	rep(i, n) {
		if (((n - 1) & i) == i) { hoge ^= b[i]; }
	}
	cout << hoge << endl;
	return 0;
}