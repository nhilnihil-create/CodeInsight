#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn=2e5+1;
void solve()
{
	ll M;
	cin>>M;
	vector<pair<ll,ll>> num;
	for(ll i=0;i<M;i++)
	{
		ll x,y;
		cin>>x>>y;
		num.push_back({x,y});
	}
	ll sumdigit=0,countdigit=0;
	for(ll i=0;i<M;i++)
	{
		sumdigit+=(num[i].second*num[i].first);
		countdigit+=(num[i].second);
	}
	//cout<<sumdigit<<" "<<countdigit<<"\n";
	ll ans=countdigit-1+((sumdigit-1)/9);
	cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll T=1,p=0;
	//cin>>T;
	do
	{
		solve();
		p++;
	}while(p<T);
	return 0;
}

