#include <cstdio>
#include <queue>

#define mp std::make_pair
#define fi first
#define se second
typedef long long LL;
typedef std::pair<int, int> pii;
const int MN = 200005;

int N, A[MN], B[MN];
std::priority_queue<pii> pq;
LL Ans;

inline int nx(const int &x) { return x % N + 1; }
inline int ls(const int &x) { return (x - 2 + N) % N + 1; }

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i) scanf("%d", &B[i]);
	for (int i = 1; i <= N; ++i) {
		if (B[i] < A[i]) return puts("-1"), 0;
		if (B[i] > A[i]) pq.push(mp(B[i], i));
	}
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		int i = p.se, v = p.fi;
		int x = B[ls(i)] + B[nx(i)], t = (v - A[i]) / x;
		if (!t) return puts("-1"), 0;
		Ans += t;
		B[i] -= t * x;
		if (B[i] > A[i]) pq.push(mp(B[i], i));
//		for (int i = 1; i <= N; ++i) printf("%d%c", B[i], " \n"[i == N]);
	}
	printf("%lld\n", Ans);
	return 0;
}

/*
6
1 1 1 1 1 1
1 1 9 5 1 1

*/
