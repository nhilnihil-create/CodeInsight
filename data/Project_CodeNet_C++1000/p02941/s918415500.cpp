#include <iostream>
#include <cstdio>
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;

ll n, ans, a[N], b[N];
priority_queue<pair<ll, ll>> pq;
int main() {
	int i, x, y, z;
	cin >> n;
	for(i=0; i<n; i++) scanf("%lld", &a[i]);
	for(i=0; i<n; i++) {
		scanf("%lld", &b[i]);
		pq.push({b[i], i});
	}
	while(!pq.empty()) {
		i = pq.top().second;
		pq.pop();
		if(b[i] == a[i]) continue;
		if(b[i] < a[i]) return puts("-1")*0;
		y = b[(i-1+n)%n] + b[(i+1)%n];
		z = (b[i] - a[i]) / y;
		if(z==0) return puts("-1")*0;
		ans += z;
		b[i] -= z * y;
		pq.push({b[i], i});
	}
	cout << ans;
	return 0;
}