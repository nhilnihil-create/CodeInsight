#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define forA(i,a,n,x) for(ll i=a;i<n;i+=x)
#define forD(i,a,n,x) for(auto i=n-1;i>=0;i-=x)
#define ranit(it,n) for(auto it:n)
#define testCases ll t;cin>>t;while(t--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define init(a,x) memset(a,x,sizeof(a))

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	string s; cin>>s; 
	
	ll n = s.length(); if(s[n-1]=='s') cout<<s<<"es"; else cout<<s<<"s";

	return 0;
}