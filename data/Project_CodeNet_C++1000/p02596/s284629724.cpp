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
	int k; cin >> k;
	
	int val = 7 % k;
	for (int i = 1; i < 1e7; ++i) {
		if (val == 0) {
			cout << i << endl;
			return 0;
		}
		val = (val * 10 + 7) % k;
	}
	cout << -1 << endl;
    return 0;
}