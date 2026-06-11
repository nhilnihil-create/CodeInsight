#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define debug1(a) cout<<#a<<" "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<" "#c<<" "<<(c)<<endl;
typedef long double ld;
void solve()
{
	ll n;
	cin >> n;
	vector<ll> arr(n);
	vector<ll> res;
	rep(i, n)
	{
		cin >> arr[i];
	}
	ll j = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == j)
		{
			res.push_back((i + 1));
			j++;
		}
	}
	if (res.size() == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] != (i + 1))
			{
				cout << -1 << endl;
				return;
			}
		}
		cout << 0 << endl;
	}
	else
	{
		ll sum = res[0] - 1;
		for (int i = 1; i < res.size(); i++)
		{
			sum += (res[i] - res[i - 1] - 1);
		}
		if (res[res.size() - 1] != n)
		{
			sum += n - res[res.size() - 1];
		}
		if (sum > n - 1)
		{
			cout << -1 << endl;
			return;
		}
		cout << sum << endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
}