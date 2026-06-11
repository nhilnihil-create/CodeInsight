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
	// ABC140-D, 1112, 52:57, WA(UNSOLVED), 
	int n, k;
	string s, invs;
	cin >> n >> k >> s;
	vector<int> v;
	int ans = 0;
	int changed = 0;
	for (int i = 1; i < n; ++i) {
		if (s[i - 1] == s[i]) ans++;
		else changed++;
	}
	changed++;
	if (changed == 1) {
		cout << ans << endl;
		return 0;
	}
	int i = 0;
	for (i = 0; i < k; ++i) {
		if (changed <= 2) break;
		ans += 2;
		changed -= 2;
	}
	if (changed == 2 && i != k) ans++;
	cout << ans << endl;
	return 0;
}