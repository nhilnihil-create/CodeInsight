#include<bits/stdc++.h>
using namespace std;
int first(long long x)
{
	int ans=-1;
	while(x)
	{
		x/=2;
		ans++;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n,i,ans=0;
	cin>>n;
	vector<long long>v(n);
	for(i=0;i<n;i++)
	{
		cin>>v[i];
		ans^=v[i];
	}
	for(i=0;i<n;i++)
		v[i]^=v[i]&ans;
	vector<long long>basis(60,0);
	for(auto x:v)
	{
		while(x && basis[first(x)])
			x^=basis[first(x)];
		if(x)basis[first(x)]=x;
	}
	long long ans2=0;
	for(i=59;i>=0;i--)
		ans2=max(ans2,ans2^basis[i]);
	cout<<ans+ans2*2<<'\n';
}
