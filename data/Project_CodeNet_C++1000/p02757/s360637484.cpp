// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;

	if(p==5||p==2) {

		long long ans = 0;
		for(int i = 0; i < n; i++) {
			if((s[i]-'0')%p==0) ans+=(i+1);
		}
		cout << ans;
		exit(0);
	}

	int pw = 1;

	vector<long long> hs(n);

	for(int i = n-1; i >= 0; i--) {
		hs[i] = ((s[i] - '0') * pw) % p;
		if(i != n - 1) hs[i] = (hs[i] + hs[i+1]) % p;
		pw = (pw * 10) % p;
	}

	map<int,int> mp;

	long long ans = 0;

	for(int i = n - 1; i >= 0; i--) {
		if(hs[i] == 0) ans++;
		ans += mp[hs[i]];
		mp[hs[i]]++;
	}

	cout << ans;
	

	return 0;
}
