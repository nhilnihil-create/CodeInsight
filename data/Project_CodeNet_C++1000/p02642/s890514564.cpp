#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;

typedef long long ll;
int main() {
	int n, ans = 0;
	cin >> n;
	vector< int > a(n);
	vector< int > b(1000111);
	for (auto& e:a) cin >> e, b[e]++;
	for (int i=0; i<n; i++) {
		bool f = 1;
		for (int j=1; j*j<=a[i]; j++) {
			if (a[i] % j == 0) {
				int x = j, y = a[i]/j;
				int nn = b[x];
				if (x == a[i]) nn--;
				if (nn > 0) {
					f=0;
					break;
				}
				
				nn = b[y];
				if (y == a[i]) nn--;
				if (nn > 0) {
					f=0;
					break;
				}
			}
		}
		
		if (f) ans++;
	}
	cout << ans << '\n';

	return 0;
}
