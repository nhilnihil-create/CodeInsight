#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200005;

int n, a[N];

ll ans = 0;
ll cnt[N];

int main() {

	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d", a + i);

	for(int i = 0; i < n; i++) {
		ans -= cnt[ a[i] ] * (cnt[ a[i] ] - 1) / 2;
		cnt[ a[i] ]++;
		ans += cnt[ a[i] ] * (cnt[ a[i] ] - 1) / 2;
	}

	for(int i = 0; i < n; i++) {
		ans -= cnt[ a[i] ] * (cnt[ a[i] ] - 1) / 2;
		cnt[ a[i] ]--;
		ans += cnt[ a[i] ] * (cnt[ a[i] ] - 1) / 2;

		printf("%lld\n", ans);
		
		ans -= cnt[ a[i] ] * (cnt[ a[i] ] - 1) / 2;
		cnt[ a[i] ]++;
		ans += cnt[ a[i] ] * (cnt[ a[i] ] - 1) / 2;
	}
}
