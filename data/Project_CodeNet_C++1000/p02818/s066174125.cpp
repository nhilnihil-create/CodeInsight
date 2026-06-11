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
	ll t,a,k;
	cin>>t>>a>>k;
	if(t>=k)
	{
		cout<<t-k<<" "<<a<<endl;
	}
	else if(t<k&&(t+a)>=k)
	{
		ll cha = k-t;
		cout<<0<<" "<<a-cha<<endl;
	}
	else
	{
		cout<<"0 0\n";
	}
	return 0;
}