#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	ll n;
	cin>>n;
	ll A[n];
	ll ans=0;
	for(ll i=0;i<n;i++){
		cin>>A[i];
	}
	
	sort(A,A+n);
	ans+=A[n-1];
	ll x=n-2;
	for(ll i=n-3;i>=0;i--){
		ans+=A[x];
		i--;
		if(i>=0)
			ans+=A[x];
		x--;
	}

	cout<<ans<<endl;
}

