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
map<int, int> mp;
inline void divisor(int n)
{
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			mp[i] = !mp[i];
			if (i * i != n)	mp[n / i] = !mp[n / i];
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	int num = 0;
	vector<bool> ball(n, false);
	vector<int> ans;
	for (int i = n - 1; i >= 0; --i) {
		ball[i] = a[i];
		int sum = 0;
		for (int j = 2*(i + 1); j <= n; j += i + 1) {
			sum += ball[j - 1];
		}
		if (sum % 2 == 1)	ball[i] = !ball[i];
		if (ball[i]) {
			num++;
			ans.push_back(i + 1);
		}
	}
	cout << num << endl;
	rep(i, num)	cout << ans[i] << " ";
	return 0;
}
