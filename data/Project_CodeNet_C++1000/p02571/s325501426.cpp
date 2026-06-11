#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ll n=0,k=0,ans=0;
	string s,t;
	cin>>s>>t;
	n=s.length();
	k=t.length();
	ans=k;
	for(int i=0;i<=n-k;i++){
		ll cnt=0;
		for(ll j=0;j<k;j++){
			if(s[i+j]!=t[j]) cnt++;
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<'\n';
	return 0;
}
