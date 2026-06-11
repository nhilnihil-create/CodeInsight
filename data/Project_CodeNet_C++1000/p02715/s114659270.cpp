#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;
typedef long long ll;

ll n, k, ans, M=1e9+7, c[N];

ll pow(ll p, ll q) {
	ll re = 1;
	while(q) {
		if(q&1) re = re * p % M;
		p = p * p % M;
		q >>= 1;
	}
	return re;
}

int main() {
	ll i, j;
	cin >> n >> k;
	for(i=k; i; i--) {
		c[i] = pow(k/i, n);
		for(j=2*i; j<=k; j+=i) c[i] = (c[i] - c[j] + M) % M;
		ans = (ans + c[i] * i) % M;
	}
	cout << ans;
	return 0;
}