#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 7;

ll p[64];
ll a[N];
bool vis[N];

void ins(ll x) {
	for (int i = 60; ~i; i--) {
		if (!vis[i]) continue;
		if (x >> i & 1) {
			if (!p[i]) {
				p[i] = x;
				break;
			}
			x ^= p[i];
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), sum ^= a[i];
	ll res = 0;
	for (int i = 60; ~i; i--)
		if (!(sum >> i & 1)) vis[i] = 1;
	for (int i = 1; i <= n; i++)
		ins(a[i]);
	for (int i = 60; ~i; i--)
		if (vis[i] && !(res >> i & 1)) res ^= p[i];
	printf("%lld\n", res + (sum ^ res));
	return 0;
}