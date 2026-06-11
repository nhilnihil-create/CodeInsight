#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <cctype>
#include <random>

using namespace std;
typedef long long  ll;
const ll INF = 1000000007;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)


int main() {
	ll N;
	cin >> N;
	ll ans = 0;
	for (int i = 1; i < N; i++) {
		ans += floor((double)(N - 1) / i);
	}
	cout << ans << endl;
	return 0;
}