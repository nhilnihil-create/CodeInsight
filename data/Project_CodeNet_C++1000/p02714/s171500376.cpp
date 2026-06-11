#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}


int main()
{
	int n;
	string s;
	cin >> n >> s;

	ll r = 0, g = 0, b = 0;
	rep(i, n)
	{
		if (s[i] == 'R') r++;
		else if (s[i] == 'G') {
			g++;
		}
		else {
			b++;
		}
	}

	ll ans = r * g * b;
	for (int i = 0; i < n; ++i)
	{
		for (int j = (i + 1); j < n; ++j)
		{
			if (s[i] == s[j]) continue;
			int k = 2 * j - i;
			if (k >= n || s[i] == s[k] || s[j] == s[k]) continue;
			ans--;
		}
	}

	cout << ans << endl;
	return 0;
}