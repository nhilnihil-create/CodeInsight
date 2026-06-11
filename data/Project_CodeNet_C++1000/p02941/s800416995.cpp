#include <cstdio>
#include <queue>
#define int long long
using namespace std;
const int NC = 2e5 + 5;
int N, A[NC], B[NC];
int pre(int i) { return (i == 1) ? N : (i - 1); }
int nxt(int i) { return (i == N) ? 1 : (i + 1); }
struct cmp {
	bool operator()(const int &x, const int &y) { return B[x] < B[y]; }
};
priority_queue<int, vector<int>, cmp> H;
signed main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; ++i) scanf("%lld", &B[i]);
	for (int i = 1; i <= N; ++i) if (A[i] != B[i]) H.push(i);
	int ans = 0;
	while (H.size()) {
		int tp = H.top();
		H.pop();
		int dec = (B[tp] - A[tp]) / (B[pre(tp)] + B[nxt(tp)]);
		if (dec == 0 && B[tp] != A[tp]) {
			printf("-1\n");
			return 0;
		}
		B[tp] -= dec * (B[pre(tp)] + B[nxt(tp)]);
		ans += dec;
		if (B[tp] != A[tp])
			H.push(tp);
	}
	printf("%lld\n", ans);
	return 0;
}