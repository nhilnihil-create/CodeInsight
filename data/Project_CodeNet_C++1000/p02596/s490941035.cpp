#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;

int main() {
	FASTIO
	ll k;
	cin >> k;
	ll y = 7 % k ;
	ll z = 10 % k ;
	int c = 1;
	vector<bool> m( k + 1);
	while(y){
		y = y * z + 7;
//		clog << y << endl;
		y %= k;
		c++;
		if(m[y]){
			return cout << -1 << endl,0;
		}
		m[y] = 1;
	}
	cout << c << endl;

}
