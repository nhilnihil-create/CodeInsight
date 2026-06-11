#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int h,n;
vector<int>arr1,arr2;
vector<ll>visited(10001);
vector<ll>memo(10001);
ll dp(ll var)
{
	if(var<=0)
	 return 0;
	if(visited[var])
	 return memo[var];
	visited[var]=1;
	ll mx=1e9;
	for(int i=0; i<n; i++){
		mx=min(mx,arr2[i]+dp(var-arr1[i]));
	}
	memo[var]=mx;
	return memo[var];
}
int main()
{
	cin>>h>>n;
	arr1.resize(n);
	arr2.resize(n);
	for(int i=0; i<n; i++){
		cin>>arr1[i]>>arr2[i];
	}
	ll ans=dp(h);
	cout<<ans;
	return 0;
}