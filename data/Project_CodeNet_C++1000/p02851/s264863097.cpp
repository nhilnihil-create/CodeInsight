#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[200010],s[200010];
map<ll,ll> cnt;
ll pmod(ll x){
	return(x%k+k)%k;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll ans=0;
	for(int i=n;i>=1;i--){
		cnt[(s[i]-i)%k]++;
		if(i+k-1<=n){
			int tt=i+k-1;
			cnt[(s[tt]-tt)%k]--;
		}
		ll tmp=(s[i-1]-i+1ll)%k;
		ans+=cnt[tmp];
	}
	cout<<ans<<endl;
	return 0;
}