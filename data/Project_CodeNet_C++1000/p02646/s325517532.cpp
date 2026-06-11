#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, v, b, w, t;
	cin >> a >> v >> b >> w >> t;
	
	if (a < b) {
		a += v*t;
		b += w*t;
		if (b <= a) cout << "YES" << endl;
		else cout << "NO" << endl;
	} else {
		a -= v*t;
		b -= w*t;
		if (a <= b) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}