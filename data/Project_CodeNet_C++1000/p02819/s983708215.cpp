#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;

bool prime(int x) {
	bool flag = 1;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)flag = 0;
	}
	return flag;
}
int main() {
	int x, ans;
	cin >> x;
	for (int i = x; i < 2 * x + 1; i++) {
		if (prime(i) == 1) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
