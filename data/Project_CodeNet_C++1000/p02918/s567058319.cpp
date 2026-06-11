#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;
int main() {
	int cng = 0;
	int ans = 0;
	int ansr = 0, ansl = 0;
	int l = 0, r = 0;
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i + 1])cng++;
		else if (s[i] == s[i + 1] )ans++;
		//else if (s[i] == s[i + 1] && s[i] == 'L')ansl++;
		
	}
	if (s[0] == s[n - 1]) {
		if (cng/2 <= k) {
			ans = n - 1;

		}
		else {
			ans += 2 * k;
		}
	}
	else {
		if ((cng - 1) / 2 >= k) {
			ans += 2 * k;
		}
		else {
			ans = n - 1;
		}
	}
	cout << ans<<endl;
	return 0;
}