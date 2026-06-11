#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp(a, b) make_pair(a, b)
typedef pair<int, int> pii;
inline int lowbit(int x) { return (x & (-x));}
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
int d[maxn], a[maxn];
ll sum[maxn], tmp[maxn];
int main()
{
	int k, q;
	cin >> k >> q;
	for(int i = 0; i < k; ++i) cin >> d[i];
	for(int i = 1; i <= q; ++i)
	{
		int n, x, m;
		cin >> n >> x >> m;
		ll ret = x;
		for(int j = 0; j < k; ++j)
		{
			a[j] = d[j] % m;
			sum[j + 1] = sum[j] + a[j];
			tmp[j + 1] = tmp[j] + (a[j] == 0);
		}
		ret += sum[k] * ((n - 1) / k) + sum[(n - 1) % k];
		cout << n - 1 - (ret / m - x / m) - (tmp[k] * ((n - 1) / k) + tmp[(n - 1) % k]) << endl;
		 
	}
	return 0;
}
	