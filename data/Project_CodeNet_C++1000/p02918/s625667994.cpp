//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n >> k >> s;
	char	c = s[0];
	x = 0;
	for(i=1;i<n;i++) {
		if (c != s[i]) {
			for(;i<n;i++) {
				if (c == s[i]) break;
				s[i] = c;
			}
			x++;
		}
		if (x==k) break;
	}
	if (s[0] == 'L') i=1;
	else i=0;
	if (s[n-1] == 'R') n=n-1;
	for(;i<n;i++) {
		if (s[i]=='L') {
			if (s[i-1]=='L') ans++;
		} else {
			if (s[i+1]=='R') ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
