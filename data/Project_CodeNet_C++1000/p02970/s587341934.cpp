#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, d; cin >> n >> d;

	int tmp = 2 * d + 1;
	int ans;
	if (n % tmp == 0) {
		ans = n / tmp;
	}
	else {
		ans = n / tmp + 1;
	}

	cout << ans << endl;
	return 0;
}