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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<map<char,ll>,ll> mp;
	map<map<char,ll>,bool> used;
	ll n;
	cin>>n;
	vector<string> vs(n);
	for(int i=0;i<n;i++)
	{
		cin>>vs[i];
		map<char,ll> tmp;
		for(int j=0;j<vs[i].size();j++)tmp[vs[i][j]]++;
		mp[tmp]++;
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		map<char,ll> tmp;
		for(int j=0;j<vs[i].size();j++)tmp[vs[i][j]]++;
		if(used[tmp] == 1)con;
		else used[tmp] = 1; 
		ll cnt = mp[tmp]-1;
		ans+=(cnt+1)*cnt/2;
	}
	cout<<ans<<endl;
	return 0;
}