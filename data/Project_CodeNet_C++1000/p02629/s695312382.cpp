#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n;
	char arf[27] = "zabcdefghijklmnopqrstuvwxy";
	cin >> n;
	string s;
	while(n >= 0) {
		ll i = n % 26;
		s += arf[i];
		if(i == 0) n -= 26;
		n -= i;
		n /= 26;
		if(n == 0) n--;
	}
	reverse(s.begin(), s.end());
		cout << s << endl;
	return 0;
}
