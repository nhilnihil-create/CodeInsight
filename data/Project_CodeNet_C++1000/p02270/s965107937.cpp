#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for (int i=(a);i<(b);++i)

int n, k, w[100010];

bool able(int P) {
	int t = 1, p = P;

	for_(i,0,n) {
		if (p >= w[i]) {
			p -= w[i];
		} else {
			p = P - w[i];
			++t;
		}
	}
	
	return t <= k;
}

void solve() {	
	int lb = *max_element(w, w + n) - 1, ub = accumulate(w, w + n, 0) + 10;
	
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		
		if (able(mid)) ub = mid;
		else lb = mid;
	}
	
	cout << ub << endl;
}

int main() {
	cin >> n >> k;
	for_(i,0,n) cin >> w[i];
	solve();
}