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
	ll n;
	ll k;
	cin>>n>>k;
	vector<ll> vl(n);
	FOR(i,0,n)cin>>vl[i];
	vector<ll> v;
	v.push_back(0);
	FOR(i,0,n)
	{
		v.push_back(vl[i]);
		v[i+1] += v[i];
	}
	ll ma = -1;
	for(int i=0;i+k<=n;i++)
	{
		ll last = v[i+k];
		ll first = v[i];
		ma = max(ma,(last-first+k));
	}
	double ans = double(ma*1.0);
	printf("%.12f",ans/2);
	puts(" ");
	return 0;
}
