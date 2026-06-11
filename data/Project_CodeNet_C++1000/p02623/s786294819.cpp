#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll>a(n+1),b(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		b[i]+=b[i-1];
	}
	ll ans=0;
	for(int len1=0;len1<=n;len1++){
		ll time1=a[len1];
		ll len2=upper_bound(b.begin(),b.end(),k-time1)-b.begin();
		len2--;
		ll time2=b[len2];
		if(time1+time2<=k){
			ans=max(ans,len1+len2);
		}
	}
	cout<<ans<<'\n';

	return 0;
}