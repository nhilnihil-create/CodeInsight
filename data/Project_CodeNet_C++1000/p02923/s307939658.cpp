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
int main()
{
	ll n;
	cin>>n;
	vector<ll> vl(n);
	vector<ll> len;
	for(int i=0;i<n;i++)cin>>vl[i];
	ll tmp = vl[0];
	ll tlen = 1;
	for(int i=1;i<n;i++)
	{
		if(vl[i] <= tmp)
		{
			tmp = vl[i];
			tlen++;
		}
		else
		{
			len.push_back(tlen-1);tlen = 1;tmp = vl[i];
		}
	 } 
	if(tmp != -1)
	{
		len.push_back(tlen-1);
	}
	sort(all(len));
	cout<<len[len.size()-1]<<endl;
	return 0;
}