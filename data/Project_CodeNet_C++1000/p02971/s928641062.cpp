#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,ll>::iterator itll;
typedef long double ld;
typedef map<ll,ll> mapll;
typedef map<string,ll> mapstl;
#define con continue
#define pb push_back
#define fi first
#define se second
#define fr front()
#define one 1.0
#define inf 1000000000000000000
#define all(vl) vl.begin(),vl.end()
#define m_p make_pair 
#define sz(a) sizeof(a)
#define forn(mp,it) for(it = mp.begin();it!=mp.end();it++)
#define cin2(a,b) cin>>a>>b
#define cin3(a,b,c) cin>>a>>b>>c
#define cinf(vl,n) for(int i=0;i<n;i++) {ll a;cin>>a;vl.pb(a);} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	vector<ll> vl;
	cin>>n;
	cinf(vl,n);
	vector<ll> an = vl;
	sort(all(an));
	for(int i=0;i<n;i++)
	{
		if(vl[i] != an[n-1])
		{
			cout<<an[n-1]<<endl;
		}
		else
		{
			cout<<an[n-2]<<endl;
		}
	}
	return 0;
}