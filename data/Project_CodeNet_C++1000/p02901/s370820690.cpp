#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 12;
const int Maxm = 1000;
const int INF = 0x3f3f3f3f;

int N, M;
struct Node {
	int A, C;
};
Node A[100000 + 5];

int f[Maxm + 5][(1 << Maxn) + 5];

int main() {
#ifdef LOACL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d %d" ,&N, &M);
	for(int i = 1; i <= M; i++) {
		int x;
		scanf("%d %d", &A[i].A, &x);
		int t = 0;
		for(int j = 1; j <= x; j++) {
			int tmp;
			scanf("%d", &tmp);
			t |= (1 << (tmp - 1));
		}
		A[i].C = t;
	}
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for(int i = 1; i <= M; i++) {
		for(int s = 0; s < (1 << N); s++) {
			int s1 = s | A[i].C;
			f[i][s1] = min(f[i][s1], f[i - 1][s] + A[i].A);
			f[i][s] = min(f[i][s], f[i - 1][s]);
		}
	}
	if(f[M][(1 << N) - 1] != INF)printf("%d\n", f[M][(1 << N) - 1]);
	else puts("-1");
	return 0;
}
