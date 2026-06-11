#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long dx[] = {1, 0, -1, 0};
long dy[] = {0, 1, 0, -1};
using pll = pair<long, long>;
constexpr long MOD = 1000000007;

int main() {
	double d, t, s; cin >> d >> t >> s;
	if (d / t <= s) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
