//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,d,i,j,k,n,m,y,l,r,ans = 0;
	string	s;
	cin >> n >> d;
	vector<vector<ll>>	x(n , vector<ll>(d));

	for(i=0;i<n;i++) for(j=0;j<d;j++) cin >> x[i][j];

	for(i=0;i<n-1;i++) for(j=i+1;j<n;j++) {
		l = 0;
		for(k=0;k<d;k++) {
			l += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
		}
		m = sqrt(l) + 2;
		for(r=1;r<=m;r++) {
			if (r*r == l) {
				ans++;
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
