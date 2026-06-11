

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;



int main() {
	int a, b, c, k;
	cin >> a >> b >> c >> k;

	int ans = 0;

	if (a >= k) {
		ans += k;
		a -= k;
		k = 0;
	}
	else {
		ans += a;
		k -= a;
		a = 0;
	}


	k -= b;
	b = 0;
	if (k <= 0) {
		cout << ans << endl;
	}
	else {
		cout << ans - k << endl;
	}

}