#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	
	int ren = 0;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		if (a == b) ++ren;
		else ren = 0;
		if (ren == 3) {
			cout << "Yes\n";
			return 0;
		}
	}
	
	cout << "No\n";
	
	return 0;
}