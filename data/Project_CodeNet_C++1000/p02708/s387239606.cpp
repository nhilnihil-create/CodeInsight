#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
void solve(){
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	for(ll i=k;i<=n+1;i++){
		ll mn=((i*(i-1))/2)%mod;
		ll mx=((n+1)*n)/2-((n+1-i)*(n-i))/2;
		ans=((ans+mx-mn+1)%mod+mod)%mod;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int T=1;
	//cin>>T;
	while(T--)
		solve();
}

