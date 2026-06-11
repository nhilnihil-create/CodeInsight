#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;

int a, b, m, mi_a = INF, mi_b = INF;
int A[N], B[N], sol = INF;

int main(){
	scanf("%d%d%d", &a, &b, &m);
	for(int i = 0;i < a;i++)
		scanf("%d", A + i), mi_a = min(mi_a, A[i]);
	for(int i = 0;i < b;i++)
		scanf("%d", B + i), mi_b = min(mi_b, B[i]);
	for(int i = 0;i < m;i++){
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		sol = min(A[x - 1] + B[y - 1] - z, sol);
	}
	printf("%d\n", min(sol, mi_a + mi_b));
	return 0;
	
}