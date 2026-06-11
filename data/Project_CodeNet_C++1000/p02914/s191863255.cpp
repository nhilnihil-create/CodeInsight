#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 62;
ll b[K];
ll a[K];
ll c[K];
int n;

bool check(ll mask) {
	for (int i = 0; i < n; i++)
		c[i] = 0;
	int m = 0;
	for (int i = 0; i < K; i++) {
		if (((mask >> i) & 1) == 0) continue;
		for (int j = 0; j < n; j++)
			if ((a[j] >> i) & 1)
				c[j] ^= 1LL << m;
		m++;
	}
	for (int i = 0; i < m; i++)
		b[i] = -1;
	for (int i = 0; i < n; i++) {
		ll x = c[i];
		for (int j = 0; j < m; j++) {
			if (((x >> j) & 1) == 0) continue;
			if (b[j] == -1) {
				b[j] = x;
				break;
			} else {
				x ^= b[j];
			}
		}
	}
	ll x = (1LL << m) - 1;
	for (int i = 0; i < m; i++) {
		if (((x >> i) & 1) == 0) continue;
		if (b[i] == -1) return false;
		x ^= b[i];
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < K; i++)
		b[i] = -1;
	ll XR = 0;
	scanf("%d", &n);
	while(n--) {
		ll x;
		scanf("%lld", &x);
		XR ^= x;
		for (int i = 0; i < K; i++) {
			if (((x >> i) & 1) == 0) continue;
			if (b[i] == -1) {
				b[i] = x;
				break;
			} else {
				x ^= b[i];
			}
		}
	}
	n = 0;
	for (int i = 0; i < K; i++)
		if (b[i] != -1)
			a[n++] = b[i];
	ll ans = 0;
	for (int i = K - 1; i >= 0; i--) {
		if ((XR >> i) & 1) continue;
		ans ^= 1LL << i;
		if (!check(ans)) ans ^= 1LL << i;
	}
	printf("%lld\n", XR + 2 * ans);

	return 0;
}
