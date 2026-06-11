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
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == t[i])
			ans++;
	}
	cout << ans << endl;
	return 0;
}

//!