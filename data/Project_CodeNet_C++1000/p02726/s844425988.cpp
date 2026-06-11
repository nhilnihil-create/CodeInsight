#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;


using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	int b;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			b = min(j - i, abs(x - i) + abs(y - j) + 1);
			a[b]++;
		}
	}

	for (int i = 1; i < n; i++) cout << a[i] << endl;



	return 0;
}
