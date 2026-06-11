#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int main()
{
	fastio;
	lli n;
	cin>>n;
	if(n%2)
		cout<<0;
	else
	{
		lli div=10,ans=0;
		while(div<=n)
		{
			ans+=n/div;
			div*=5;
		}
		cout<<ans;
	}
	return 0;
}
