#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define COUT cout<<fixed<<setprecision(12)
#define CIN getline(cin,s)
ll MOD=1000000007;

void solve()
{
	string s;
	cin>>s;
	ll sum=0;
	for(ll i=0;i<s.size();i++)
	{
		sum=sum+s[i]-48;
	}
	if(sum%9==0)
	{
		cout<<"Yes\n";
	}
	else
	cout<<"No\n";
}
int main()
{
	ll t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
}