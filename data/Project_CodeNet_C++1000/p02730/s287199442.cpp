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

bool palindrome(string s)
{
	string k = s;
	reverse(all(s));
	return k == s;
}
bool s_palindrome(string s)
{
	string f = s.substr(0,s.size()/2);
	string l = s.substr(s.size()/2+1);
	if(!palindrome(f)||!palindrome(l)||!palindrome(s))return 0;
	return 1;
}
int main()
{
	string s;
	cin>>s;
	if(s_palindrome(s))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}
