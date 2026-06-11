#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#include <deque>
#include <set>
#include <unordered_map>
#include <complex>
#include <fstream>
#include <map>
using namespace std;
using ll = long long;
using ld = long double;
const double eps = 1e-2;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n; ll k; cin>>k;
	vector<ll> A(n);
	for(int i=0; i<n; i++) cin>>A[i];

	double r = 1.0*(*max_element(begin(A), end(A))), l = 0;
	while(r-l>eps) {
		double mid = (r+l)/2;
		bool flag = 1; ll div = 0;
		for(int i=0; i<n; i++) if(1.0*A[i]-mid>eps) {
			div+=(ceil(1.0*A[i]/mid)-1);
			if(div>k) {flag = 0; break;}
		}
		if(flag) r = mid;
		else l = mid;
	}

	ll ans = 1ll*ceil(r);
	cout << ans << '\n';

	return 0;
}