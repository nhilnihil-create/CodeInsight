#include<bits/stdc++.h>
using namespace std;

#define LL long long
set<LL> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	LL n, m, x, g = 1;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> x; x /= 2;
		if(s.find(x) == s.end()) {
			if(!i) g = x;
			g /= __gcd(x, g);
			g *= x;
		}
		s.insert(x);
	}

	for(auto x : s) {
		if((g / x) % 2 == 0) {
			cout << 0;
			return 0;
		}
	}

	g = m / g;
	g = (g+1) / 2;

	cout << g;
}