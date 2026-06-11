#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vvi vector<vi >
#define pi pair<ll,ll>
#define vvpi vector<vector<pi > >
#define vpi vector<pi >
#define vppi vector<pair<ll,pi > >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define fs first
#define se second
#define fast ios_base::sync_with_stdio(false)
#define cintie cin.tie(NULL)
vi bit(200010,0);
ll query(ll x)
{
	ll res=0;
	for(;x>0;x-=x&(-x))
	res=res+bit[x];
	return res;
}
ll update(ll x,ll f)
{
	for(;x<200005;x+=x&(-x))
	bit[x]=bit[x]+f;
}
int main()
{
	    ll n,d,a,i,x,y;
		cin>>n>>d>>a;
		vpi v;
		for(i=0;i<n;i++)
		{
			cin>>x>>y;
			v.pb(mkp(x,y));
		}
		sort(v.begin(),v.end());
		vi xc;
		for(i=0;i<n;i++)
		{
			xc.pb(v[i].fs);
		}
		ll ans=0;
		ll t=0;
		ll j;
		map<ll,ll> mp;
		for(i=0;i<xc.size();i++)
		{
			mp[xc[i]]=i+1;
		}
		ll upd,div,ind;
		for(i=0;i<n;i++)
		{
			upd=query(mp[v[i].fs]);
			ll temp=v[i].se-upd*a;
			if(temp<=0)
			continue;
			div=temp/a;
			if((temp%a)!=0)
			div=div+1;
			ans=ans+max(t,div);
		//	cout<<upd<<" "<<temp<<" "<<div<<" "<<ans<<endl;
			update(mp[v[i].fs],div);
			ind=lower_bound(xc.begin(),xc.end(),v[i].fs+2*d+1)-xc.begin();
			if(ind<n)
			update(mp[v[ind].fs],-div);
		//	for(j=1;j<=3;j++)
		//	cout<<bit[j]<<" ";
		//	cout<<endl;
		}
		cout<<ans<<endl;
}