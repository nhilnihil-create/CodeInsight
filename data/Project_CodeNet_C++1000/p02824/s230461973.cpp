#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
int main()
{
	ll n,m,v,p;
	cin >> n >> m >> v >> p;
	vector<ll> a(n);
	for(int i = 0;i<n;i++)cin >> a[i];
	ll L = 0,R = n;
	sort(a.rbegin(),a.rend());
	while(R-L>1)
	{
		ll M = (L+R)/2;
		ll cost = m*v;
		vector<P> b(n);

		for(int i = 0;i<n;i++)
		{
			b[i].first = a[i];
			b[i].second = m;
		}
		b[M].first  += m;
		b[M].second = 0;
		cost -= m;
		ll x = b[M].first;
		sort(b.begin(),b.end());
		//Mで均す
		for(int i = 0;i<n;i++)
		{
			if(x <= b[i].first)continue;
			ll now = min(cost,x-b[i].first);
			now = min(now,b[i].second);
			b[i].second -= now;
			b[i].first += now;
			cost -= now;
		}
		for(int i = 0;i<n;i++)
		{
			if(x < b[i].first)
			{
				ll now = min(cost,b[i].second);
				b[i].first+=now;
				b[i].second -= now;
				cost -= now;
			}
		}
		sort(b.rbegin(),b.rend());
		for(int i = 0;i<n;i++)
		{
			ll now = min(cost,b[i].second);
			b[i].first+=now;
			b[i].second -= now;
			cost-=now;
		}
		sort(b.rbegin(),b.rend());
		//cout << M << "x="<<x<<endl;
		//cout << "L R" << L <<' ' << R << endl;
		//cout << b[p-1].first << endl;
		//for(int i = 0;i<n;i++)cout << b[i].first << ' ' ;cout << endl;
		if(b[p-1].first<=x)L = M;
		else R= M;
	}
	cout << R << endl;
}
