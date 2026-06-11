#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005],sum[100005];
int main(){
	cin>>n;
	for(int i=0;i<=n;++i){
		cin>>a[i];
		sum[i]=a[i];
	}
	for(int i=n-1;i>=0;--i){
		sum[i]+=sum[i+1];
	}
	ll val=1,ans=0;
	for(int i=0;i<=n;++i){
		if(val<a[i]){
			cout<<"-1\n";
			return 0;
		}
		ans+=val;
		val-=a[i];
		val*=2;
		val=min(val,sum[i+1]);
	}
	cout<<ans<<'\n';
	return 0;
}