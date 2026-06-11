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

const int N = 200200;
int a[N];
int b[N];
bool inQ[N];
int Q[N];
int L, R;
ll ans = 0;
int n;

void solve(int id) {
	int p = id - 1, q = id + 1;
	if (p < 0) p += n;
	if (q >= n) q -= n;
	int k = (b[id] - a[id]) / (b[p] + b[q]);
	if (k <= 0) return;
	ans += k;
	b[id] -= (b[p] + b[q]) * k;
	solve(p);
	solve(q);
}

inline void putInQ(int id) {
	if (inQ[id]) return;
	int p = id - 1, q = id + 1;
	if (p < 0) p += n;
	if (q >= n) q -= n;
	if (b[id] < a[id] + b[p] + b[q]) return;
	inQ[id] = 1;
	Q[R++] = id;
	if (R == N) R = 0;
}

int main()
{
//	freopen("in28.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) {
//		putInQ(i);
		solve(i);
	}
/*	
	while(L != R) {
		int id = Q[L++];
		if (L == N) L = 0;
		inQ[id] = 0;
		int p = id - 1, q = id + 1;
		if (p < 0) p += n;
		if (q >= n) q -= n;
		int k = (b[id] - a[id]) / (b[p] + b[q]);
		if (k <= 0) continue;
		ans += k;
		b[id] -= k * (b[p] + b[q]);
		putInQ(p);
		putInQ(q);
	}
*/	
	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) {
			printf("-1\n");
			return 0;
		}
	printf("%lld\n", ans);

	return 0;
}
