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
	ll n,k;
	cin>>k>>n;
	vector<ll> vl(n);
	FOR(i,0,n)cin>>vl[i];
	vector<ll> dist;
	FOR(i,0,n)
	{
		if(i == 0)
		{
			dist.push_back(vl[0]+k-vl[n-1]);continue;
		}
		dist.push_back(vl[i]-vl[i-1]);
	 } 
	sort(all(dist));
	ll he = 0;
	FOR(i,0,dist.size()-1)
	{
		he+=dist[i];
	 } 
	cout<<he<<Endl;
	return 0;
} 
