#include <bits/stdc++.h>
 
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = 4*atan(1);
typedef long long ll;
typedef pair<int,int> pii;
int n, k;
// int gcd(int a, int b) { 
//     if (a == 0) return b; 
//     return gcd(b % a, a); 
// }
ll f(ll a) {
	a %= MOD;
	if(a < 0) a += MOD;
	return a;
}
ll power(int base, int power) {
	ll prod = 1;
	ll b = base;
	while(power) {
		if (power & 1) {
			prod = f(prod*b);
		}
		b = f(b*b);
		power/=2;
	}
	return prod;
}
ll ways[100005];
void solve() {
	cin >> n >> k;
	ll sum = 0;
	for (int i = k; i > 0; i--) {
		ways[i] = power(k/i,n);
		for (int j = i * 2; j <= k; j += i) {
			ways[i] = f(ways[i]-ways[j]);
		}
		sum = f(sum + f(ways[i] * i));
	}
	printf("%lld\n",sum);
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	// int t;
	// cin >> t;
	// for (int i = 1; i <= t; i++) { 
		// cout << "Case #" << i << ": ";
		solve();
	// }
}