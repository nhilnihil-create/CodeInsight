#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iomanip>
#define endl "\n"
#define debug(x) cout << #x << " : " << x << endl;
#define debug2(x, y) cout << #x << " : " << x  << ", " << #y << " : " << y << endl;
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0);
typedef long long ll;
using namespace std;

const ll maxSize = 2e6;
ll parent[maxSize];
ll size_set[maxSize];
ll cnt[maxSize];

void make_set(ll v)
{
	parent[v] = v;
	size_set[v] = 1;
}

ll find(ll v)
{
	if(v == parent[v])
		return v;
	return parent[v] = find(parent[v]);	
}

void union_set(ll a, ll b)
{
	a = find(a);
	b = find(b);

	if(a != b)
	{
		if(size_set[a] > size_set[b])
			swap(a, b);
		parent[a] = b;
		size_set[b] += size_set[a];
	}
}

int main()
{
	FASTIO

	ll n, m;
	cin >> n >> m;

	for(ll i = 1; i <= n; i ++)
		make_set(i);

	for(ll i = 0; i < m; i ++)
	{
		ll a, b;
		cin >> a >> b;
		union_set(a, b);
	}

	ll maxm = 0;
	for(ll i = 1; i <= n; i ++)	
	{
		maxm = max(maxm, size_set[i]);
	}

	cout << maxm << endl;
}