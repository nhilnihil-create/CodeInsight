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
#define cl clear()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,ll>::iterator itll;
typedef long double ld;
typedef map<ll,ll> mapll;
typedef double dou;
#define int ll
ll gcd(ll a,ll b)
{
	return (b == 0?a:gcd(b,a%b));
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}
ll getlcm(vector<ll> vl)
{
	ll ch = 1;
	for(int i=0;i<vl.size();i++)
	{
		ch = lcm(ch,vl[i]);
	}
	return ch;
}
signed main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> vl(n);
	for(int i=0;i<n;i++)
	{
		cin>>vl[i];
		vl[i]/=2;
	} 
	ll ch = getlcm(vl); 
	ll pl = ch*2;
	ll he = ch;
	for(int i=0;i<n;i++)
	{
		if((ch/vl[i])%2 == 0)
		{
			cout<<"0\n";ret 0;
		}
	}/*
	ll cnt = 1;
	if(m<ch)
	{
		cout<<"0\n";ret 0;
	}
	cnt+=((m-ch)/pl);*/
	cout<<(m+ch)/pl<<endl;
	return 0;
}