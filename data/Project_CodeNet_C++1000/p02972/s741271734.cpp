#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 100000000
#define mod 1000000007
#define ld long double
#define point complex<long double>
#define pi acos(-1)
#define IO                            \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
ll gcd(ll a,ll b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int has[n+1]={};
	for(int i=n;i>0;i--)
	{
		int val=arr[i];
		int sum=0;
		for(int ii=1;ii*i<=n;ii++)
		{
			sum+=has[ii*i];
		}
		if(sum%2!=val)
		{
			has[i]=1;
		}
		
	}
	vector<int>res;
	for(int i=1;i<=n;i++)
	{
		if(has[i])res.push_back(i);
	}
	cout<<res.size()<<endl;
	for(auto r:res)
	{
		cout<<r<<" ";
	}
	return 0;
}