#include <cstdio>
#include <vector>
using namespace std;

const int N = 50;
int n, m, q;
int qd[N][4];

std::vector<int> seq(int bit) 
{
	int j = 1;
	std::vector<int> r;
	for (int i = 0; i < m + n - 1; ++i) {
		if ((bit >> i) & 1) ++j;
		else r.push_back(j);
	}
	return r;
}
int get(std::vector<int> a) 
{
	int s = 0;
	for (int i = 0; i < q; ++i) if (a[qd[i][1] - 1] - a[qd[i][0] - 1] == qd[i][2]) s += qd[i][3];
	return s;
}

int main() 
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < q; ++i) for (int j = 0; j < 4; ++j) scanf("%d", qd[i] + j);
	int mask = 1 << (m + n - 1);
	int ans = 0;
	for (int bit = 0; bit < mask; ++bit) if (__builtin_popcount(bit) == m - 1) ans = max(ans, get(seq(bit)));
	printf("%d\n", ans);
	return 0;
}
