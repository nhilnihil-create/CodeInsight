//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL
ll	n;
ll	ans;
vector<ll>	aa(100);
vector<ll>	maxk(100);

int main() {
	ll		a,b,c,d,h,i,j,k,l,m,x,y;
	ans = 1000;
	cin >> n;
	for(i=1;i<=n;i++) cin >> aa[i];
	maxk[0] = 1000;
	for(i=1;i<=n;i++) {
		maxk[i] = maxk[i-1];
		for(j=1;j<i;j++) {
			a = (maxk[j] / aa[j]) * aa[i] + (maxk[j] % aa[j]);
			maxk[i] = max(maxk[i] , a);
		}
	}
	cout << maxk[n] << endl;
	return 0;
}
