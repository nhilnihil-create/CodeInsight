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
	const ll N=n+1;
	A[0]=A[1]=0;
	for(ll i=2;i<N;i++){
		if(A[i]==0){
			for(ll j=2*i;j<N;j+=i){
				A[j]=i;
			}
		}
	}

	S[1]=1;
	for(ll i=2;i<N;i++){
		if(A[i]==0)
			S[i]=2;
		else {
			ll x=i;
			while(x%A[i]==0)
				x/=A[i];
			if(x==1)
				S[i]=S[i/A[i]]+1;
			else 
				S[i]=S[x]*S[i/x];
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
		ans+=i*S[i];
	cout<<ans;
}
