#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

void transform(string& s) {
	for(int i = 0; i < s.size(); i++)
		s[i]--;
}

void divide(string& s) {
	for(int i = 0; i < s.size(); i++)
		s[i] = (s[i] == '2') ? '1' : '0';
}

bool odd(string s) {
	ll ans = 0;

	ll x = n-1;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1') {
			bool odd = 1;
			int k = i;
			if(x < k) continue;
			for(int j = 0; k > 0 && odd; j++, k /= 2) {
				if((i&(1<<j)) && !(x&(1<<j)))
					odd = 0;
			}

			if(odd)
				ans ^= 1;
		}
	}

	return ans;
}

bool containOne(string s) {
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1') return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	transform(s);

	if(odd(s))
		cout << "1" << '\n';
	else if(containOne(s))
		cout << "0" << '\n';
	else {
		divide(s);
		if(odd(s))
			cout << "2" << '\n';
		else
			cout << "0" << '\n';
	}

	return 0;
}