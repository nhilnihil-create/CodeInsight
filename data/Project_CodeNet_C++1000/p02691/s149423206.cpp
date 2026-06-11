#include<bits/stdc++.h>
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll>l;
	unordered_map<ll, ll>cntr;
	unordered_map<ll, vector<ll> > r;
	for (ll i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		l.pb(i + x);
		r[i - x].pb(i);
		cntr[i - x]++;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		if (cntr[l[i]])
		{
			auto it = upper_bound(r[l[i]].begin(), r[l[i]].end(), l[i]);
			ans += r[l[i]].end() - it;
		}
	}
	cout << ans << endl;
}

