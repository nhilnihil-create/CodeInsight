#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"
#include "string"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
	int l, r;
	cin >> l >> r;
	if (r - l + 1 >= 2019) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 2018 * 2018;
	for (int i = l; i <= r; ++i) {
		for (int j = i + 1; j <= r; ++j) {
			int p = i % 2019;
			int q = j % 2019;
			int r = p * q;
			r = r % 2019;
			ans = min(ans, r);
		}
	}
	cout << ans << endl;
	return 0;
}