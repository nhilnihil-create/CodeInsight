#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n, k, s; cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		if (i < k) cout << s << endl;
		else {
			if (s == 1000000000)	cout << 1 << endl;
			else cout << s + 1 << endl;
		}
	}
	return 0;
}