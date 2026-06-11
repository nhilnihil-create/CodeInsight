#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,ll>::iterator itll;
typedef long double ld;
typedef map<ll,ll> mapll;

#define con continue
#define pb push_back
#define fi first
#define se second
#define fr front()
#define INF 1000000000000000000
#define all(vl) vl.begin(),vl.end()
#define m_p make_pair 
#define sz(a) sizeof(a)
#define forn(mp,it) for(it = mp.begin();it!=mp.end();it++)
#define FOR(i,a,n) for(int i=a;i<n;i++) 
#define FORE(i,a,n) FOR(i,a,n+1)
#define Endl endl
#define eNdl endl
#define enDl endl
#define endL endl

int main()
{
	ll x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	vector<P> vl;
	FOR(i,0,a)
	{
		ll m;
		cin>>m;
		vl.pb(P(m,2));
	}
	FOR(i,0,b)
	{
		ll m;
		cin>>m;
		vl.pb(P(m,1));
	}
	FOR(i,0,c)
	{
		ll m;
		cin>>m;
		vl.pb(P(m,0));
	}
	sort(all(vl));
	reverse(all(vl));
	ll num = x+y;
	ll ans = 0;
	ll cnt = 0;
	for(int i=0;(i<a+b+c&&cnt<num);i++)
	{
		if(vl[i].se == 2&&x)
		{
			ans+=vl[i].fi;x--;cnt++;
		}
		else if(vl[i].se == 1&&y)
		{
			ans+=vl[i].fi;y--;cnt++;
		}
		else if(vl[i].se == 0)
		{
			ans+=vl[i].fi;cnt++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
