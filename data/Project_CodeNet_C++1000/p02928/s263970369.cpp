#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long int ll;

ll modi(ll a,ll n){
	if(n==0)
		return 1;
	else{
	    if(n%2==0){	      
         	ll temp=modi(a,n/2);	              
		    return (temp*temp)%MOD;		
        }
        else{
              return(a*modi(a,n-1))%MOD;	
        }
    }
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
        
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(a[i]>a[j]){
				if(i<j){
					ll add=((k*(k+1))%MOD*modi(2,1000000005))%MOD;
					ans=(ans+add)%MOD;
				}
				else{
					ll add=((k*(k-1))%MOD*modi(2,1000000005))%MOD;
					ans=(ans+add)%MOD;
				}
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}