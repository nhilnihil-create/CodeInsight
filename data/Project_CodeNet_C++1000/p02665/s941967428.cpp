#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
ll hell=pow(10,15);
void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n+1),per(n+1,0);
	for(ll i=0;i<=n;i++)
	cin>>v[i];
	if(!n){
		if(v[0]==1)
		cout<<"1";
		else
		cout<<"-1";
		exit(0);
	}
	if(v[0]){
		cout<<"-1";
		exit(0);
	}
	per[0]=1;
	for(ll i=1;i<=n;i++){
		per[i]=2*min(per[i-1],hell)-v[i];
		if(per[i]<0){
			cout<<"-1";
			exit(0);
		}
	}
	ll res=v[n],cur=v[n];
	for(ll i=n-1;i>=0;i--){
		ll val=min(per[i],cur);
		if(2*val<cur){
			cout<<"-1";
			exit(0);
		}
		cur=v[i]+val;
		if(!cur){
			cout<<"-1";
			exit(0);
		}
		res+=cur;
	}
	cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll qc=1;
    for(ll i=1;i<=qc;i++)
    solve();
}
