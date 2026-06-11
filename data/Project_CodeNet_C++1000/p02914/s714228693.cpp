#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

ll n, a[100010], rese, r, b, sum;
priority_queue<ll> pq;
vector<ll> e;
bool containB(ll x, int bits) {
	return (x >> bits) & 1ll;
}
void GaussE(int bits) {
	if (pq.empty() || !containB(pq.top(), bits))
		return;
	ll model = pq.top();
	pq.pop();

	for (ll& val : e)
		if (containB(val, bits))
			val ^= model;
	e.emplace_back(model);
	while (!pq.empty() && containB(pq.top(), bits)) {
		ll cur = pq.top();
		pq.pop();
		pq.emplace(cur ^ model);
	}
}
int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", a + i), r ^= a[i];
	sum = r;
	for (int i = 0; i < n; i++)
		a[i] ^= a[i] & r, pq.emplace(a[i]);
	for (int i = 59; 0 <= i; i--)
		GaussE(i);
	ll exor = 0;
	for (ll val : e)
		exor ^= val;
	printf("%lld\n", sum + exor * 2);
}