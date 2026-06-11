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
	ll cnt=0;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<3;i++){
		if(s[i]==t[i]){
			cnt++; 
		} 
	}
	cout<<cnt<<"\n";
	return 0;
}