#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll k, x; cin >> k >> x;
	ll left = x - (k - 1);
	ll right = x + (k - 1);
	for (int i = left; i <= right; i++) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}