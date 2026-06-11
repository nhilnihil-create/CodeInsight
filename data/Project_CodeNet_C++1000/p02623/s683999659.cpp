#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	ll n, m, k;
	cin>>n>>m>>k;
	ll A[n+1]={};
	ll B[m+1]={};
	for(ll i=1;i<=n;i++){
		cin>>A[i];
		A[i]+=A[i-1];
	}
		
	for(ll j=1;j<=m;j++){
		cin>>B[j];
		B[j]+=B[j-1];
	}
	
	ll ans=0;
	ll x=n, y=0;
	
	while(x>=0 && y<=m){
		if(A[x]+B[y]<=k){
			ans=max(ans, x+y);
			y++;
		} else{
			x--;
		}
	}


	
	


	cout<<ans<<endl;
}
