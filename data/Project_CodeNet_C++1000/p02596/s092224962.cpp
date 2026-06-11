#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pll pair<ll,ll> 

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll k;
	cin>>k;
	ll A[k];
	A[0]=7%k;
	for(ll i=1;i<k;i++){
		A[i]=(A[i-1]*10+7)%k;
	}
	ll ans=-1;
	for(ll i=0;i<k;i++){
		if(A[i]==0){
			ans=i+1;
			break;
		}
	}

	cout<<ans<<endl;

}
