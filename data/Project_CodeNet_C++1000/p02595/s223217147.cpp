#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 

typedef long long ll;
using namespace std;
const ll m = 1e9 + 7;
ll solve(ll x, ll y) {
	ll X = x * x;
	ll Y = y * y;
	return X + Y;
	
}
int main() {
	ll n, d; cin >> n >> d;
	ll cnt = 0;
	while (n--) {
		ll x, y; cin >> x >> y;
		ll res = solve(x, y);
		if (res <= d * d) 
		{
			
			cnt++;
		}

	}
	cout << cnt << endl;
    return 0;
}