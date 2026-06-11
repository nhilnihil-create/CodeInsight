#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 9;
const ll N   = 500500;

int main()
{
	fio
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	ll n, i, j, k;
	cin>>n;
	vector<pair<ll, ll>>v;
	for(i=0;i<n;i++)
	{
		ll a, b;
		cin>>a>>b;
		v.push_back({a, b});
	}
	bool ok = true;
	ll cnt = 0;
	for(auto x:v)
	{
		if(x.first==x.second)
		{
			cnt++;
			if(cnt==3)
			{
				cout<<"Yes\n";
				return 0;
			}
		}
		else
			cnt = 0;
	}
	cout<<"No\n";
	return 0;
}