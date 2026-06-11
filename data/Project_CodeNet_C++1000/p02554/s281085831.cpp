#include<iostream>
#include<math.h>
#include<algorithm>
typedef long long ll;

using namespace std;

const int mod1 = 1e9 + 7;
ll n;

ll ksm(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1)ans = (ans * a) % mod1;
		a = (a * a) % mod1;
		b = b / 2;
	}
	return ans;
}

int main() {
	cin>>n;
	cout << (ksm(10, n) % mod1 - (ksm(9, n) * 2) % mod1 + ksm(8, n) % mod1 + mod1) % mod1;
	return 0;
}