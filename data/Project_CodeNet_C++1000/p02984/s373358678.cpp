#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n)	cin >> a[i];
	ll diff = 0;
	diff = a[0] - a[1];
	for (int i = 2; i < n; i += 2) {
		diff += (a[i % n] - a[(i + 1) % n]);
	}
	vector<ll> ans(n);
	ll cur = 0;
	ans[0] = (diff + a[0]) / ll(2);
	for (int i = n - 1; i > 0; --i) {
		ans[i] = a[i] - ans[(i + 1) % n];
	}
	rep(i, n)	cout << ll(2) * ans[i] << " ";
	return 0;
}