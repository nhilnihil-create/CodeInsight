#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
typedef int ll;

using namespace std;


int main() {
	
	const ll m = 2019;
	string s;
	cin >> s;
	s += '0';
	
	vector<ll> v(m, 0);
	
	
	ll p = 1;
	ll t = 0;
	for (ll i = s.length() - 1; i >= 0; i--)
	{
		ll d = s[i] - '0';
		t = (d * p + t) % 2019;
		p = (p * 10) % 2019;
		
		//printf("%2d %2d %4d\n", i, d, t);
		v[t] ++;
	}
	
	ll ans = 0;
	for (auto w :v)
		ans += (w * (w-1))/2;
	
	cout << ans << endl;
	
	return 0;
}