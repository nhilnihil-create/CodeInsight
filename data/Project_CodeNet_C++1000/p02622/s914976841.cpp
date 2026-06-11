#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	string s, w;
	cin>>s>>w;
	ll ans=0;
	for(ll i=0;i<s.size();i++)
		ans+=s[i]!=w[i];
	cout<<ans<<endl;
}

