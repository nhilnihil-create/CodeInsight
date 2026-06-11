#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int n; cin >> n;
	vector<Int> a(n);
	for(auto &i:a) cin >> i;
	vector<Int> c(n, 0);
	for(auto i:a) ++c[i-1];
	vector<Int> d(n+2, 0);
	for(auto i:c) ++d[i];
	vector<Int> e(d);
	for(Int i=0; i<n+1; ++i)
		e[i] *= i;
	for(Int i=1; i<n+1; ++i)
		e[i] += e[i-1];
	for(Int i=n; i>=0; --i)
		d[i] += d[i+1];
	vector<Int> f(n+1);
	f[0] = n;
	for(Int i=1; i<n+1; ++i)
		f[i] = (e[i] + i*d[i+1]) / i;
	Int tmp = n;
	for(Int i=0; i<n; ++i){
		while(tmp > 0 && f[tmp] < i+1) --tmp;
		cout << tmp << "\n";
	}
//	for(Int i=0; i<n+1; ++i)
//		cout << " " << d[i] << " " << e[i] << " " << f[i] << "\n";
}