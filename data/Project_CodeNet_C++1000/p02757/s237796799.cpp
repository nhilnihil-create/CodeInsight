#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int ll

void debug(map <int, int> &mp) {
	cout << "New " << endl;
	for (auto &i : mp) {
		cout << i.first << " " << i.second << endl;
	}
}

signed main ()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p;
	cin >> n >> p;
	int ans = 0;
	string s;
	cin >> s;

	if (p == 2) {
		for (int i = n - 1; i >= 0; i--) {
			int digit = s[i] - '0';
			if (digit % 2 == 0) {
				ans += i + 1;
			}
		}

		cout << ans << endl;
		return 0;
	}

	if (p == 5) {
		for (int i = n - 1; i >= 0; i--) {
			int digit = s[i] - '0';
			if (digit % 5 == 0) {
				ans += i + 1;
			}
		}

		cout << ans << endl;
		return 0;
	}

	map <int, int> mp;
	mp[0] = 1;

	int temp = 1;
	int current = 0;

	for (int i = n - 1; i >= 0; i--) {
		int digit = s[i] - '0';
		current = (current + (temp * digit) % p) % p;
		ans += mp[current];
		mp[current]++;
		temp *= 10;
		temp %= p;
		//debug(mp);
	}

	cout << ans << endl;


	return 0;
}
