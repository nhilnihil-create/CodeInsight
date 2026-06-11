// #include C/C++ {
#include <bits/stdc++.h>
// }
using namespace std;
// #typedef {
typedef long long int64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
// }

// #parameter{
#ifdef _DEBUG

#define TYPE decltype
#define RF(filename) {freopen((filename), "r", stdin);}
#define WF(filename) {freopen((filename), "w", stdout);}
#define DF(filename) {freopen((filename), "w", stderr);}
#define eprintf printf

#else

#define TYPE __typeof
#define RF(filename) {;}
#define WF(filename) {;}
#define DF(filename) {;}
#define eprintf(...)
#define fprintf(...)

#endif

// #define {
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define MP make_pair
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ALL(it) (it).begin(), (it).end()
#define FILL(__space, __val) memset(__space, __val, sizeof(__space))
#define MOVE(__spaceTo, __spaceFrom) memmove(__spaceTo, __spaceFrom, sizeof(__spaceTo))
#define UNIQUE(__vector) sort(ALL(__vector)), __vector.resize(unique(ALL(__vector)) - __vector.begin())
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
/////////////////////////////////////////////////////////////
const double PI = acos(-1.0);
const double EPS = 1e-6;

#define MAX_N 105
#define MAX_M 55
#define MOD (int)(1e9+7)
#define INF ((1 << 30) - 1)
#define BINF ((1LL << 62) - 1LL)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
inline void ADD(int x, int y) {
	printf("%d %d\n", x, y);
}
/////////////////////////////////////////////////////////////
int main() {
	RF("input.txt");
	// WF("output.txt");
	DF("err.txt");

	int N;
	scanf("%d", &N);
	int one_count = 0;
	for (int x = N; x > 0; x >>= 1) if (x & 1) one_count++;
	if (one_count == 1) return puts("No"), 0;
	puts("Yes");
	ADD(1, 2);
	ADD(2, 3);
	ADD(3, N + 1);
	ADD(N + 1, N + 2);
	ADD(N + 2, N + 3);
	vector <int> connect(N + 1);
	connect[2] = N + 2;
	connect[3] = 3;
	for (int i = 4; i < N; i += 2) {
		ADD(i, i + 1);
		ADD(i, N + 1);
		ADD(N + i, N + i + 1);
		ADD(N + i + 1, N + 1);
		connect[i] = i;
		connect[i + 1] = N + i + 1;
	}
	if (N & 1 ^ 1) {
		for (int i = 2; i < N; i++) {
			if ((N ^ i ^ 1) < N) {
				ADD(N, connect[i]);
				ADD(N + N, connect[N ^ i ^ 1]);
				break;
			}
		}
	}
	return 0;
}