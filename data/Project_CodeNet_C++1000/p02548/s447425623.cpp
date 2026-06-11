#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	// string s;
	// cin >> s;
	// if (s[(int)s.size()-1] != 's') {
		// cout << s << 's';
	// } else {
		// cout << s <<  "es";
	// }
	// int N;
	// cin >> N;
	// vector< bool > v(N);
	// for(int i=0; i<N; i++) {
		// int x,y;
		// cin >> x >> y;
		// v[i] = (x == y);
		
	// }
	// bool y = 0;
	// for (int i=2; i<N; i++) {
		// bool yy = 1;
		// for (int j=i-2; j<=i; j++) {
			// yy &= v[j];
		// }
		// y |= yy;
	// }
	// cout << (y ? "Yes" : "No");
	int N;
	cin >> N;
	ll ans = 0;
	for (int i=1; i<N; i++) {
		for (int j=1; i*j<N && j<N; j++) {
			ans ++;
		}
	}
	cout << ans;
	return 0;
	
}
