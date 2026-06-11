#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
void solve(){
	ll n,m,k;
	ll count=0;
	cin>>n>>m>>k;
	vector<ll> prefA(200005),prefB(200005);
	prefA[0]=0;
	prefB[0]=0;
	for(int i=1;i<=n;i++){
		ll temp;
		cin>>temp;
		prefA[i]=prefA[i-1]+temp;
	}
	for(int i=1;i<=m;i++){
		ll temp;
		cin>>temp;
		prefB[i]=prefB[i-1]+temp;
	}
	for(int i=0;i<=n;i++){
		if(prefA[i]>k)break;
		ll rem = k - prefA[i];
		ll l=0,r=m,ans,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(prefB[mid]<=rem){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		count=max(count,i+ans);
	}
	cout<<count<<"\n";
}
int main(){
	FASTIO
	solve();
	return 0;
}
