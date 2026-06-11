#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
ll n;
cin>>n;
vector<pair<string,ll>> v;
for(int i = 0;i<n;i++)
{
	string s;
	ll t;
	cin>>s>>t;
	pair<string,ll> p = {s,t};
	v.push_back(p);
}
string x;
cin>>x;
bool check = 0;
ll ans = 0;
for(auto it = v.begin();it!=v.end();it++)
{
	if(check)
	{
		ans+=it->second;
	}
	if(it->first==x)
	{
		check=1;
	}
}
cout<<ans<<"\n";
}
