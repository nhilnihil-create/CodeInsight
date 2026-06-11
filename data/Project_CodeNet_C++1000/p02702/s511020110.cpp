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
	string s;
	cin >> s;
	int n = s.size();
	int m = 2019;
	reverse(s.begin(), s.end());
	ll ans = 0;
	vector<int> cnt(m);
	int tot = 0;
	int x = 1;
	rep(i, n) {
		cnt[tot]++;
		tot += (s[i] - '0')*x;
		tot %= m;
		ans += cnt[tot];
		x = (x * 10) % m;
	}
	cout << ans << endl;
	return 0;
}