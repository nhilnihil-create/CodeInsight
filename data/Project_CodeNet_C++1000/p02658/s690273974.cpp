#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	ll ans = 1;
	vector<ll> a;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > 1000000000000000000/ans) {
			cout << -1 << endl;
			return 0;
		}
		else {
			ans *= a[i];
		}
	}
	cout << ans << endl;
	return 0;
}