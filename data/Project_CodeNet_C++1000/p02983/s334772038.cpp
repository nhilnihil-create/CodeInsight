#include "bits/stdc++.h"
using namespace std;

int main() {
	long long L,R;
	cin >> L>>R;
	long long ans = (L * (L + 1) % 2019);
	for (long long l = L;l<R;++l) {
		for (long long r = l + 1;r<=R;++r) {
			if (0 == l * r % 2019) {
				cout << 0 <<  endl;
				return 0;
			}
			ans = min(ans, (l*r)%2019);
		}
	}
	cout << ans << endl;
	return 0;
}
