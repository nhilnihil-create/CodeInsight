#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

template <typename T>
inline T gi()
{
	T f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

const int INF = 0x3f3f3f3f, N = 200003, M = N << 1;

int n;
string s;
map <string, int> p;

int main()
{
	//File("");
	n = gi <int> ();
	for (int i = 1; i <= n; i+=1)
	{
		cin >> s;
		sort(s.begin(), s.end());
		++p[s];
	}
	LL ans = 0;
	for (auto x : p)
		ans += 1ll * x.second * (x.second - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}
