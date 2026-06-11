#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
int main() {
	ll n;
	cin>>n;
	ll ch[200010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll ans[200010]={};ll ans2=0;
	for(ll i=n-1;i>=0;i--){
		ll now=i+1;
		ll keta=2;
		ll cnt=0;
		while(now*keta<=n){
			if(ans[now*keta]){
				cnt++;
			}
			keta++;
		}
		if(cnt%2!=ch[i]){
			ans[i+1]=1;
			ans2++;
		}
	}
	cout <<ans2<<endl;
	for(ll i=1;i<=n;i++){
		if(ans[i]==1){
		cout <<i<<" ";
		}
	}
	// your code goes here
	return 0;
}