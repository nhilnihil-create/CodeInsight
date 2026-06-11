//https://www.youtube.com/watch?v=83yW2Pp6HMk&t=200s
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


const int mod = 2019;


void solve()
{
	string s;
	cin >> s;
	const int n = s.length();
	long long suff = 0, ans = 0, p = 1;
	vector<int> cnt(mod, 0);
	cnt[suff]++; //Case of empty suffix
	for (int i = n - 1; i >= 0; i--)
	{
			suff = (suff + (s[i]-'0') * p) % mod;
			p = (p * 10) % mod;
			ans += cnt[suff];
			cnt[suff]++;
	}
	cout << ans << endl;
}
int main()
{
	
	solve();
	
	return 0;
}
