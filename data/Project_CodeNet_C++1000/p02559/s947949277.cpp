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
struct Fenwick
{
	vector<lli> bit;
	int n;
	Fenwick(int n)
	{
		this->n = n;
		bit.assign(n, 0);
	}
	Fenwick(vector<lli> a): Fenwick((int)a.size())
	{
		for (int i = 0; i < (int)a.size(); ++i)
			add(i, a[i]);
	}
	lli sum(int idx)
	{
		lli res = 0ll;
		for (; idx >= 0; idx = (idx & (idx + 1)) - 1)
			res += bit[idx];
		return res;
	}
	lli sum(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
	void add(int idx, int delta)
	{
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, q = 0, ch = 0, p = 0, l = 0, r = 0; lli x = 0ll;
	cin >> n >> q;
	vector<lli> a(n);
	for (auto &i : a)
		cin >> i;
	Fenwick v(a);
	for (int i = 0; i < q; ++i)
	{
		cin >> ch;
		if (ch == 0)
		{
			cin >> p >> x;
			v.add(p, x);
		}
		else
		{
			cin >> l >> r;
			cout << v.sum(l, r - 1) << "\n";
		}
	}
}