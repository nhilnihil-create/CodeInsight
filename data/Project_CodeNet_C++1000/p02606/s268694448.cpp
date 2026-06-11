#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	int l, r, d, ans;
	cin >> l >> r >> d;
	if (l % d == 0 || r % d == 0) {
		ans = (r - l) / d + 1;
	}
	else {
		ans = (r - l) / d;
	}
	cout << ans << endl;
	return 0;
}