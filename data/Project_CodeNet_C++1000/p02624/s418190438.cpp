#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 

vector<ll> S(10000006, 0);
vector<ll> A(10000006, 0);

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	

	ll n;
	cin>>n;
	
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll k=n/i;
		ans+=i*k*(k+1)>>1;
	}
	cout<<ans<<endl;
}
