#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, b, n) for (int i = b; i < (b)+(n); i++)
using namespace std;
using ll = long long;

int main() {
	int a=0, b=0, c=0, k=0;
	cin >> a >> b >> c >> k;
	rep(i, k) {
		if (a >= b) b *= 2;
		else if (b >= c) c *= 2;
	}
	if (a < b && b < c) cout << "Yes\n";
	else cout << "No\n";
}