#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pob pop_back
#define vi vector<ll>
#define mp make_pair
#define sz size()
#define rep1(i,n) for( i=1;i<=n;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define maxx 2*100005
#define se second
#define fi first
#define be begin()
#define en end()
#define sortv(v) sort(v.begin(),v.end());
#define w() ll _;cin>>_;while(_--)
#define edge pair<ll,ll>
#define pq priority_queue<ll>
#define mod 1000000007
#define Endl "\n"
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
using namespace std;


int main()
{
	fast;
	ll n;
	cin>>n;
	ll i;
	ll a[n];
	vector<ll>v;
	//ll k=0;
	ll x=1;
	rep(i,n) cin>>a[i];
	rep(i,n)
	{
		if(a[i]==x)
		{
			v.pb(x);
			x++;
		}
	}
	if(v.size()==0)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<n-v.size()<<endl;
	}
	
	return 0;
}