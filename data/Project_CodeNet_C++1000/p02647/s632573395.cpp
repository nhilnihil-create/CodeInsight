#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
ll a[200005],pre[200005];
void solve(){
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	cin>>a[i];
	while(k){
		ll f=0;
		for(ll i=1;i<=n;i++){
			if(a[i]<n)
			f=1;
			pre[i]=0;
		}
		pre[0]=pre[n+1]=0;
		if(!f)
		break;
		for(ll i=1;i<=n;i++){
			pre[max(ll(0),i-a[i])]++;
			pre[min(n,i+a[i])+1]--;
		}
		for(ll i=1;i<=n;i++){
			pre[i]+=pre[i-1];
			a[i]=pre[i];
		}
		k--;
	}
	for(ll i=1;i<=n;i++)
	cout<<a[i]<<" ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++)
    solve();		
}
