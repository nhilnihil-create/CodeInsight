#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")
//#pragma GCC target("sse4")

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	if((n & (n - 1)) == 0)
	{
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	bool was = false;
	for(int i = 3; i <= n; i += 2)
	{
		int u = i - 1, v = i;
		if(u == (n ^ (n - 1) ^ 1) || u == n - 1)
			swap(u, v);
		if(!was)
		{
			cout << "1 " << u << "\n";
			was = true;
		}
		cout << u << " " << v << "\n";
		cout << v << " " << n + 1 << "\n";
		cout << n + 1 << " " << n + u << "\n";
		cout << n + u << " " << n + v << "\n";
	}
	if(n % 2 == 0)
	{
		cout << n << " " << n - 1 << "\n";
		cout << (n ^ (n - 1) ^ 1) << " " << n + n << "\n";
	}
	return 0;
}