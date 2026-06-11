#include <cstdio>
#include <map>
using namespace std;

map<int, int> m;
int n;

int main() 
{
	scanf("%d", &n);
	long long r = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		scanf("%d", &v);
		r += m[i - v];
		++m[v + i];
	}
	printf("%lld\n", r);
	return 0;
}
