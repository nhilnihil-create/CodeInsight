#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
 
int main() {
	FASTIO
	
	int n;
	cin >> n;
	vector<int> h(n);
	for(int& x : h) cin >> x;
	ll total = 0;
	for(int i=1; i<n; i++) {
		if(h[i] < h[i-1]) {
			total += (ll) h[i-1]-h[i];
			h[i] = h[i-1];
		}
	}
	cout << total << "\n";
	
	return 0;
}