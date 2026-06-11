#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200010;
int f[N], s[N];

int fd(int x)
{
	if (f[x] != x)
		f[x] = fd(f[x]);
	return f[x];
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ )
		f[i] = i, s[i] = 1;
		
	int x, y;
	while (m -- )
	{
		scanf("%d%d", &x, &y);
		int fx = fd(x), fy = fd(y);
		if (fx != fy)
		{
			s[fx] += s[fy];
			f[fy] = fx;
		}
	}
	
	int mx = 0;
	for (int i = 1; i <= n; i ++ )
		mx = max(mx, s[fd(i)]);
	printf("%d\n", mx);
	
	return 0;
}