#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
int main()
{
	ll n;
	cin>>n;
	vector<ld> vd(n);
	for(int i=0;i<n;i++)
	{
		cin>>vd[i];
	}
	sort(all(vd));
	ld cnt = 0;
	for(int i=0;i<n;i++){
		if(i == 0)
		{
			cnt = vd[i];con;
		}
		cnt = (cnt+vd[i])/2.0;
	}
	cout<<cnt<<endl;
	return 0;
}