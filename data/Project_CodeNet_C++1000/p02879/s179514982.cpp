#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)
#define rrep(i, j, n) for(size_t i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
constexpr ll MAX = 800000;


int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	if (a <= 9 && b <= 9) cout << a * b;
	else cout << -1;
	return 0;

}
