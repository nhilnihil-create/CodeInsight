#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100010;

int n;
ll a[N], x1, x2, S;
struct lb {
	ll p[62];
	void insert(ll x) {
		for(ll i = 61; i >= 0; --i) {
			if(!((S >> i) & 1) && ((x >> i) & 1)) {
				if(p[i]) x ^= p[i];
				else {
					p[i] = x;
					return;
				}
			}
		}
		for(ll i = 61; i >= 0; --i) {
			if(((S >> i) & 1) && ((x >> i) & 1)) {
				if(p[i]) x ^= p[i];
				else {
					p[i] = x;
					return;
				}
			}
		}
	}
} B;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]), S ^= a[i];
	for(int i = 1; i <= n; ++i) B.insert(a[i]);
	for(int i = 60; i >= 0; --i) if(!((S >> i) & 1) && !((x1 >> i) & 1)) x1 ^= B.p[i];
	for(int i = 60; i >= 0; --i) if(((S >> i) & 1) && ((x1 >> i) & 1)) x1 ^= B.p[i];
	printf("%lld\n", x1 + (S ^ x1));
	
}