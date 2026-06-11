#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstring>
#include <tuple>

using namespace std;

typedef long long LL;
typedef vector<int> Array;
typedef pair<int, int> P;

const int INF = 1 << 29;
const LL MOD = 1000000009;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define all(c) (c).begin(), (c).end()

struct edge{ int t, d; };

int main()
{
	int n, k;
	while (cin >> n && n)
	{
		cin >> k;
		vector<LL> sums(n);
		rep(i, n)
		{
			cin >> sums[i];
			if (i != 0)
				sums[i] += sums[i - 1];
		}
		LL ans = sums[k];
		for (int i = 0; i + k < n; i++)
		{
			ans = max(ans, sums[i + k - 1] - sums[i - 1]);
		}
		cout << ans << endl;
	}
	return 0;
}