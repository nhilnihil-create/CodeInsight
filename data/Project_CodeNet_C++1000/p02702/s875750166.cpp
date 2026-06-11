// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	reverse(s.begin(), s.end());
	vector<int> pre(n, 0);
	int p = 1;
	for(int i = 0; i < n; i++) {
		pre[i] = ( (s[i] - '0') * p ) % 2019;
		if(i) pre[i] = (pre[i] + pre[i-1]) % 2019;
		p = (p * 10) % 2019;
	}
	vector<int> con(2020, 0);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		if(pre[i] == 0) ans++;
		ans += con[pre[i]];
		con[pre[i]]++;
	}
	cout << ans;
	return 0;
}
