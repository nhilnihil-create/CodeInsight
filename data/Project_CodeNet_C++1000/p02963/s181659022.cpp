#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll sqint(ll num){

	ll l = 0;
	ll r = 1e10;

	while(r - l > 1){
		ll mid = (r + l) / 2;
		(mid * mid <= num ? l : r) = mid;
	}
	return r;
}



int main()
{
	ll s; cin >> s;
	if(s == 1000000000000000000) {
		cout << 0 << " " << 0 << " " << 1000000000 << " " << 0 << " " << 0 << " " << 1000000000 << endl;
		return 0;
	}

	cout << 0 << " " << 0 << " ";
	ll sq = sqint(s);
	ll a = sq, b = sq;
	if(sq * (sq - 1) >= s) {
		a--;
	}

	ll aaa = a * b - s;
	if(aaa > 1e9) {
		return 1;
	}

	cout << a << " " << 1 << " " << aaa << " " << b << endl;
}