#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<ll> member;
vector<ll> food;
ll n,k;

bool possible (ll val)
{
	ll all_sum=0;
	for (ll i=0;i<=n-1;i++)
	{
		ll diff=max((ll)0,member[i]-(val/food[n-1-i]));
		all_sum=all_sum+diff;
	}

	if (all_sum>k)
	{
		return false;
	}
	else
	{
		return true;
	}
}

ll search (ll start,ll end)
{
	//cout << start << " ----- " << end << endl; 
	if (start==end)
	{
		return start;
	}
	else
	{
		ll mid=(start+end)/2;
		bool check=possible(mid);
		if (check)
		{
			return search(start,mid);
		}
		else
		{
			return search(mid+1,end);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);

	cin >> n >> k;
	member.resize(n);
	food.resize(n);

	for (ll i=0;i<=n-1;i++)
	{
		cin >> member[i];
	}

	for (ll i=0;i<=n-1;i++)
	{
		cin >> food[i];
	}

	sort(member.begin(),member.end());
	sort(food.begin(),food.end());

	ll max_val=LLONG_MIN;
	for (ll i=0;i<=n-1;i++)
	{
		ll local=member[i]*food[n-1-i];
		max_val=max(max_val,local);
	}

	cout << search(0,max_val) << endl;
	return 0;
}