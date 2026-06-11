/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
vector<int> parent;
int FIND(int node)
{
	if (node == parent[node])
		return node;
	return parent[node] = FIND(parent[node]);
}
void DSU(int a, int b)
{
	a = FIND(a); b = FIND(b);
	if (a != b)
		parent[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, q = 0, ch = 0, x = 0, y = 0;
	cin >> n >> q;
	parent.resize(n);
	for (int i = 0; i < n; ++i)
		parent[i] = i;
	for (int i = 0; i < q; ++i)
	{
		cin >> ch >> x >> y;
		if (ch == 0)
			DSU(FIND(x), FIND(y));
		else
		{
			if (FIND(x) == FIND(y))
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}