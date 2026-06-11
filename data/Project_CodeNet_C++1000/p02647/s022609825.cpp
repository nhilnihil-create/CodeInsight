//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	string	s;
	cin >> n >> k;
	vector<ll>	aa(n),ans(n);
	for(i=0;i<n;i++) cin >> aa[i];

	for(x=0;x<k;x++) {
		for(i=0;i<n;i++) ans[i] = 0;
		for(i=0;i<n;i++) {
			if (i-aa[i] >= 0) ans[i-aa[i]]++;
			else ans[0]++;
		}
		for(i=0;i<n;i++) {
			if (i+1+aa[i] < n) ans[i+1+aa[i]]--;
		}
		for(i=1;i<n;i++) {
			ans[i] += ans[i-1];
		}
		for(i=0;i<n;i++) aa[i] = ans[i];
		a = 1;
		for(i=0;i<n;i++) if (aa[i]!=n) a = 0;
		if (a) break;
	}

	for(i=0;i<n;i++) {
		if (i>0) cout << " ";
		cout << aa[i];
	}

	cout << endl;
	return 0;
}
