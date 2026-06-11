#include<bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;
typedef long long int lli; 

string s;
lli a,n,b,c,t,temp1,temp2,x,y,temp,q,d,k,mod=1e9+7;
vector<lli>v(300005);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	map<lli,lli>mp;
	
	cin>>n;
	lli val=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		mp[a]++;
		v[i]=a;
	}
	
	vector<lli>ans;
	for(auto x:mp)
	{
		val+=(x.second*(x.second-1)/2);	
	}
	
	for(int i=0;i<n;i++)
	{
		ans.pb(val-(mp[v[i]]*(mp[v[i]]-1)/2)+((mp[v[i]]-1)*(mp[v[i]]-2)/2));
	}
	
	for(auto x:ans)cout<<x<<endl;
}
