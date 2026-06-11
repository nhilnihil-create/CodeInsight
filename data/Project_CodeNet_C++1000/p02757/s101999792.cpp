#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
	// your code goes here
	int n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	//int val[n];
	ll ans=0;
	if(p==2 || p==5)
	{
		for(int i=0;i<n;i++)
		{
			if((s[i]-'0')%p==0)
			ans+=i+1;
		}
		cout<<ans;
		return 0;
	}
	
	unordered_map<ll,ll>mp;
	ll sum[n+1];
	sum[n]=0;
	int power=1;
	for(int i=n-1;i>=0;i--)
	{
		sum[i]=sum[i+1]+power*(s[i]-'0');
		sum[i]=sum[i]%p;
		power=power*10;
		power=power%p;
		// mp[sum[i]]++;
	}
	for(int i=0;i<=n;i++)
	mp[sum[i]]++;
	for(auto x:mp)
	ans+=((x.second-1)*x.second)/2;
	cout<<ans;
	
	
	

     
	return 0;
}