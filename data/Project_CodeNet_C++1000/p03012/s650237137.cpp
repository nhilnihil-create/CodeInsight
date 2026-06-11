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
	vector<ll>	w(n+1);
	for(i=1;i<=n;i++) {
		cin >> a;
		w[i] = w[i-1] + a;
	}
	for(t=1;t<n;t++) {
		a = w[t];
		b = w[n] - w[t];
		ans = min(ans , abs(a-b));
	}

	cout << ans << endl;
	return 0;
}
