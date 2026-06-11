#include<iostream>
#define ll long long
using namespace std;
ll pre[1000000+5];
ll find(ll i)
{
	if (i == pre[i])return i;
	return pre[i] = find(pre[i]);
}
void merge(ll x, ll y)
{
	ll fx = find(x), fy = find(y);
	if (fx != fy)pre[fx] = fy;
}
int main()
{
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		pre[i] = i;
	for (ll i = 0; i < m; i++)
	{
		ll a, b;
		cin >> a >> b;
		merge(a, b);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == i)ans++;
	}
	cout << ans-1 << endl;
}
