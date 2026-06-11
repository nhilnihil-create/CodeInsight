//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = -1;
	string	s;
	cin >> k;

	a = 7;
	for(i=1;i<=k;i++) {
		if (a%k==0) {
			ans = i;
			break;
		}
		a = (a%k)*10 + 7;
	}
	cout << ans << endl;
	return 0;
}
