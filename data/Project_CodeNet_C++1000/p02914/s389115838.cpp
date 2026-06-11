#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 어떻게 xor basis까지 사랑하겠어...
//
bool chosen[100000];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	ll all = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		all ^= a[i];
	}
	for(int b=59; b>=0; b--) {
		if(all&(1ll<<b)) continue;
		for(int i=0; i<n; i++) {
			if(chosen[i]) continue;
			if(a[i]&(1ll<<b)) {
				//printf("at b=%d, %lld at position %d is chosen\n", b, a[i], i);
				chosen[i] = 1;
				ll v = a[i];
				for(int j=0; j<n; j++) {
					if(i==j) continue;
					if(a[j]&(1ll<<b))
						a[j] ^= v;
				}
/*				for(int j=0; j<n; j++) {
					printf("%lld ", a[j]);
				}
				puts("");*/
				break;
			}
		}
	}
	memset(chosen, 0, sizeof chosen);
	ll add = 0;
	for(int b=59; b>=0; b--) {
		if(all&(1ll << b)) continue;
		for(int i=0; i<n; i++) {
			if(chosen[i]) continue;
			if(a[i]&(1ll<<b)) {
				//printf("b=%d: added %lld\n", b, a[i]);
				chosen[i] = 1;
				add ^= a[i];
			}
		}
	}
	cout << (add + (all^add));
}