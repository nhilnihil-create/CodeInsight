/*
Author: Sanskar Agarwal
Nick: sanskaragarwal
Birla Institute Of Technology, Mesra
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define INF 100009
#define mod 1000000007
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define test while(t--)solve();

void solve()
{
	int n;
	cin >> n;
	int arr[n];
	int x = 0;
	set<int> s;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		x ^= arr[i];
		mp[arr[i]]++;
		s.insert(arr[i]);
	}
	if (s.size() == 1 && *s.begin() == 0)
	{
		cout << "Yes" << endl;
		return;
	}
	if (s.size() == 2)
	{
		auto i = s.begin();
		auto j = s.rbegin();
		if ((2 * n) % 3 == 0 && mp[*j] == (2 * n / 3) && mp[*i] == n / 3)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		return;
	}
	if (x != 0 || s.size() != 3)
	{
		cout << "No" << endl;
		return;
	}
	auto i = s.begin();
	int t = mp[*i];
	for (i; i != s.end(); ++i)
	{
		if (mp[*i] != t)
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main()
{

	fast
	int t;
	t = 1;
	// cin >> t;
	test;
#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
	return 0;
}