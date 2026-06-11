#include <iostream>
#include <cstdio>
#define N 200005
using namespace std;

typedef long long ll;
ll n, m, sz, ans, a[N], v[N], k[N];
int main()
{
	ll i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
	}
	j = a[1];
	for (i = 1; i < m; i++, j = a[j]) {
		if (v[j] != 0) {
			sz = i - v[j];
			ans = (m - v[j]) % sz + v[j];
			cout << k[ans] << endl;
			return 0;
		}
		v[j] = i;
		k[i] = j;
	}
	cout << j << endl;
    return 0;
}
