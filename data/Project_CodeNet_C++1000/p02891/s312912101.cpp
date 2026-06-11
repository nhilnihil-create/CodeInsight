#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	string k; cin >> k;
	string s = k;
	ll cnt = 0;
	ll n = k.size(), t; cin >> t;

	if(count(k.begin(), k.end(), k.front()) == n) {
		cout << (t * n) / 2 << endl;
		return 0;
	}
	
	for(int i = 1; i < n; i++) {
		if(s[i - 1] == s[i]) {
			s[i] = 0;
			cnt++;
		}
	}

	if(k.front() != k.back()) {
		cout << t * cnt << endl;
	}else {
		ll a = 1, b = 1;
		for(int i = 1; i < n; i++) {
			if(k[i] == k[i - 1])a++;
			else break;
		}
		for(int i = n - 2; i >= 0; i--) {
			if(k[i] == k[i + 1])b++;
			else break;
		}

		cout << (t * cnt) - ((a / 2) + (b / 2) - ((a + b) / 2)) * (t - 1) << endl;
	}

}