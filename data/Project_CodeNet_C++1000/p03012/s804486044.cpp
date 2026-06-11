//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,t,i,j,k,l,m,n,x,y;
	ll		ans = INF;
	string	s;
	cin >> n;
	vector<ll>	w(n);
	for(i=0;i<n;i++) cin >> w[i];

	for(t=0;t<n-1;t++) {
		a = b = 0;
		for(i=0;i<n;i++) {
			if (i<=t) a += w[i];
			else b += w[i];
		}
		ans = min(ans , abs(a-b));
	}

	cout << ans << endl;
	return 0;
}
