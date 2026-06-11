#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll search(vector<ll> &a,ll val)
{
	// cout<<" vector ";
	// for(int i=0;i<a.size();i++)
	// 	cout<<a[i]<<" ";
	// cout<<endl;
	ll low=0,high=a.size()-1;
	if(val>=a.back())
		val=-1;
	while(low<high)
	{
		ll mid=(low+high)>>1;
		if(a[mid]<=val)
			low=mid+1;
		else
			high=mid;
	}
	return a[low];
}

int main()
{
	string s,t;
	cin>>s>>t;
	vector<vector<ll> > ms(26),mt(26);
	for(int i=0;i<s.length();i++)
		ms[s[i]-'a'].push_back(i);
	for(int i=0;i<t.length();i++)
		mt[t[i]-'a'].push_back(i);
	// for(int i=0;i<26;i++)
	// {
	// 	if(ms[i].size()>0)
	// 	{
	// 		cout<<char(i+'a')<<" -< ";
	// 		for(int j=0;j<ms[i].size();j++)
	// 			cout<<ms[i][j]<<" ";
	// 		cout<<endl;
	// 	}
	// }
	for(int i=0;i<26;i++)
	{
		if(mt[i].size()>0&&ms[i].size()==0)
		{
			cout<<-1;
			return 0;
		}
	}
	ll ans=0;
	ll curr=-1;
	for(int i=0;i<t.length();i++)
	{
		ll z=search(ms[t[i]-'a'],curr);
		// cout<<z<<endl;
		if(z<=curr)
			ans++;
		curr=z;
	}
	cout<<ans*s.length()+curr+1;
}