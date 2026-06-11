#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

void mkay(ll& a){
	if(a >= mod)
		a -= mod;
}

int main(){
	int n, d; cin >> n >> d;
	int ans = 0;
	for(int i = 0; i < n; i++){
		double s, p, q;
		cin >> p >> q;
		s = sqrt(p * p + q * q);
		if(s <= d)
			ans++;
	}
	cout << ans << endl;
}