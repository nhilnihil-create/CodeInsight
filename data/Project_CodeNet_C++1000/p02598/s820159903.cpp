#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int n, k; cin >> n >> k;
	vector<Int> a(n);
	for(auto &i:a) cin >> i;
	double l = 1e-5, r = 1e9;
	for(Int i=0; i<100; ++i){
		double m = (l + r) / 2;
		Int t = 0;
		for(auto j:a){
			t += max(0, (int)(((double)j - 1e-5) / m));
		}
//		cerr << l << " " << m << " " << r << " " << t << "\n";
		if(t <= k) r = m;
		else l = m;
	}
	cout << (Int)(r + 1) << "\n";
}