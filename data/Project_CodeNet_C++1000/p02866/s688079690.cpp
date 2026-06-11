#include <bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("O3")
//#pragma GCC target("sse4")
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define FILL(a, value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(), a.end()
 
typedef long long LL;
typedef pair<int, int> PII;

const int mod = 998244353;
const int MAX = 1 << 17;

int mult(int a, int b)
{
	return (LL)a * b % mod;
}

int c[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		int d;
		cin >> d;
		if(i == 0 && d)
		{
			cout << "0\n";
			return 0;
		}
		c[d]++;
	}
	if(c[0] != 1)
	{
		cout << "0\n";
		return 0;
	}
	int s = 1, ans = 1;
	for(int i = 0; c[i + 1]; i++)
	{
		FOR(j, 0, c[i + 1])
			ans = mult(ans, c[i]);
		s += c[i + 1];
	}
	cout << (s == n ? ans : 0) << "\n";
	return 0;
}
