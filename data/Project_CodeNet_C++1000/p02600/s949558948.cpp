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
#define one 1.0
#define inf 1000000000000000000
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
#define PI 3.14159265358979323846

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a;
	cin>>a;
	if(a<=599)cout<<"8\n";
	else if(a<=799)cout<<"7\n";
	else if(a<=999)cout<<"6\n";
	else if(a<=1199)cout<<"5\n";
	else if(a<=1399)cout<<"4\n";
	else if(a<=1599)cout<<"3\n";
	else if(a<=1799)cout<<"2\n";
	else cout<<"1\n";
	return 0;
}