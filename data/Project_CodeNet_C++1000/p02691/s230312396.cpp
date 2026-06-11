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
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC166-E, 1007, 
	int n;
	cin >> n;
	ll ans = 0;
	vector<int> a(n);
	map<int, int> mp;
	rep(i, n) {
		cin >> a[i];
		int b = i + a[i];
		mp[b]++;
	}
	rep(i, n) {
		ans += mp[i - a[i]];
	}
	cout << ans << endl;
	return 0;
}