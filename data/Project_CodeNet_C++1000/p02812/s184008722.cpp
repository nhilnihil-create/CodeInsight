#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=0;
	for(ll i=0;i<n-2;i++)
	{
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')
			ans++,i+=2;
	}
	cout<<ans;
	return 0;
}

