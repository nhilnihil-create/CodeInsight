#include<bits/stdc++.h>
using namespace std;

#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

const int maxr = 1e5 + 5;


int32_t main()
{
	GO;
	string s, t;
	cin >> s >> t;
	int ans = 1e16;
	for (int i = 0; i <= s.size() - t.size(); i++) {
		int count = 0;
		for (int j = 0; j < t.size(); j++) {
			if (s[i + j] != t[j])
				count++;
		}
		ans = min(ans, count);
	}
	cout << ans << endl;
	return 0;
}

//!