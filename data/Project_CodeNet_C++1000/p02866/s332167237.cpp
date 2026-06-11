#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[114514],cnt[114514];
int main() {
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
			cin>>a[i];
			cnt[a[i]]++;
	}
	ll ans=1,mod=998244353;
	if(a[0]==0||cnt[0]>1){
		for(int i=1;i<n;i++){
			ans*=cnt[a[i]-1];
			ans%=mod;
		}
	}else ans=0;
	cout<<ans;
	return 0;
}
