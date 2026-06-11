#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;

int main(){
	FASTIO
	ll n, d;
	cin >> n >> d;
	d = d * d;
	ll c = 0;
	for (int i= 0 ; i < n ; i++){
		ll a, b;
		cin >> a >> b;
		a = a * a + b * b;
		if(a <= d)
			c++;
	}
	cout << c << endl;
}