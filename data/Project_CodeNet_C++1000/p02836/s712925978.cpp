#include<bits/stdc++.h>
#define ll long long int
#define vll vector<pair<ll, ll> >
#define vl vector<ll>
#define vi vector<int>
#define vii vector<pair<int, int> >
const ll mod = 1e9 + 7;
using namespace std;

ll power_mod(ll x, ll y, ll p)
{
	ll ans = 1;
	x = x%p;
	if(x==0)
	return p;

	while(y>0)
	{
		if(y&1)
		{
			ans = (ans*x)%p;
		}
		y = y>>1;
		x = (x*x)%p;
	}
	return ans;
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	getline(cin, s);
	while(s.length()==0)
	getline(cin, s);
	
	ll i,j,k,l,m,n;
	ll sum=0;
	for(i=0;i<s.length()/2;i++)
	{
	    if(s[i]!=s[s.length()-1-i])
	    sum++;
	}
	cout<<sum<<"\n";
	return 0;
}
