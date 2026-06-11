#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
#include <chrono>
#include <random>
#include <ctime>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = 3.14159265358979323846;
const ll MOD = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	map<int, vector<int>> m;
	ll ans = 0;
	m[0].push_back(0);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		sum = (sum + x) % k;
		ll ind = ((sum - i - 1) % k + k) % k; 
		auto it = lower_bound(m[ind].begin(), m[ind].end(), i - k + 2);
		ans += m[ind].end() - it;
		m[ind].push_back(i + 1);
	}
	cout << ans;
}