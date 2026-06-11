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
	string s;
	cin>>s;
	ll q;
	cin>>q;
	bool rev = 0;
	string fr,ls;
	FOR(i,0,q)
	{
		ll a;
		cin>>a;
		if(a == 1)
		{
			rev^=1;
			continue;
		}
		ll b;
		cin>>b;
		char c;
		cin>>c;
		ll pos = (b-1)^rev;
		if(pos == 0)fr.insert(fr.begin(),c);
		else ls+=c;
	}
	s = fr+s+ls;
	if(rev)reverse(all(s));
	cout<<s<<endl;
	return 0;
}
