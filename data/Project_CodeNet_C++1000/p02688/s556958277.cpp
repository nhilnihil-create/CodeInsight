#include <cstdio>
using namespace std;

const int N = 100;
bool u[N];
int n, k;

int main() 
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int d;
		scanf("%d", &d);
		for (int i = 0; i < d; ++i) {
			int v;
			scanf("%d", &v);
			u[v - 1] = true;
		}
	}
	int c = 0;
	for (int i = 0; i < n; ++i) c += !u[i];
	printf("%d\n", c);
	return 0;
}
