#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;

int main() {
	speed;
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>a(n), b(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
	int tmp = 0, ans = 0;
	vector<int>t;
	while (k > 0 && a.size())
		k -= a.back(), t.push_back(a.back()), a.pop_back(), ++tmp;
	if (k < 0)
		k += t.back(), t.pop_back(), --tmp;
	ans = tmp;
	while (t.size() && b.size()) {
		while (b.back() > k && t.size())
			k += t.back(), t.pop_back(), tmp--;
		while (b.size() && k >= b.back())
			k -= b.back(), b.pop_back(), tmp++;
		ans = max(ans, tmp);
	}
	cout << ans;
}