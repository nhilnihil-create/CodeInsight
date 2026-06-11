#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<iterator>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define t ll t;cin>>t;while(t--)
#define nn cout<<endl;
#define ff(a,n) for(ll i=a;i<n;i++)
int main()
{
	ll n; cin>>n;
	map<string,ll>m;
	map<string,ll>::iterator y;
	ff(0,n)
	{
		string s;
		cin>>s;
		m[s]++;
	}
/*	for(y=m.begin();y!=m.end();y++)
	{
		cout<<y->first<<" "<<y->second<<endl;
	}*/
/*	for(auto &x:m)
	{
		cout<<x.first<<" "<<x.second<<endl;
	}*/
	ll max=0;
	for(auto &x:m)
	{
		ll v=x.second;
		if(v>max) max=v;
	}
	for(auto &x:m)
	{
		if(x.second==max)cout<<x.first<<endl;
	}
	
}