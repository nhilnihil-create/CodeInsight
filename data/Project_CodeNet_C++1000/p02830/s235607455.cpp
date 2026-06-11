#include<bits/stdc++.h>
#define con continue
#define pb push_back
#define fi first
#define se second
#define fr front()
#define one 1.0
#define inf 1000000000000000000
#define ret return
#define all(vl) vl.begin(),vl.end()
#define sor sort 
#define cl clear
#define m_p make_pair 
#define sz(a) a.size()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,ll>::iterator itll;
typedef long double ld;
typedef map<ll,ll> mapll;
typedef map<string,ll> mapstl;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<n;i++)cout<<s[i]<<t[i];
	cout<<endl;
	return 0;
}