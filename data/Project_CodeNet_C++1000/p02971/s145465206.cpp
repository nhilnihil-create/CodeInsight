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
#define FOR(i,a,n) for(ll i=a;i<n;i++) 
#define FORE(i,a,n) FOR(i,a,n+1)
#define Endl endl
#define eNdl endl
#define enDl endl
#define endL endl

int main()
{
	ll n;
	cin>>n;
	vector<ll> t;
	vector<ll> vl(n);
	FOR(i,0,n)cin>>vl[i];
	t = vl;
	sort(all(vl));
	reverse(all(vl));
	FOR(i,0,n)
	{
		if(t[i] == vl[0])cout<<vl[1]<<endl;
		else cout<<vl[0]<<endl;
	}
	return 0;
}
