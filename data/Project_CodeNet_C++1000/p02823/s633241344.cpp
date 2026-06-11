#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll n;
	cin >> n;
	ll a, b;
	cin >> a >> b;
	ll stagesub = b - a;
	if (stagesub % 2 == 0) {
		cout << stagesub / 2 << endl;
	}
	else {
		ll index = min(a - 1, n - b);
		if (index == a - 1) {
			b -= index;
			cout << index +1 + (b-1) / 2 << endl;
			
		}
		else if (index == n - b) {
			a += n - b;
			cout << index +1+ (n-a) / 2 << endl;
		}

	}
	return 0;
}