#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n;
ll d, a, ans, c[mxN+1];
ar<int, 2> b[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> a;
	for(int i=0; i<n; ++i) {
		cin >> b[i][0] >> b[i][1];
	}
	sort(b, b+n);
	for(int i=0, j=0; i<n; ++i) {
		while(j<n&&b[j][0]<=b[i][0]+2*d)
			++j;
		ll need=max((b[i][1]-c[i]*a+a-1)/a, 0ll);
		ans+=need;
		c[i]+=need;
		c[j]-=need;
		c[i+1]+=c[i];
	}
	cout << ans;
}
