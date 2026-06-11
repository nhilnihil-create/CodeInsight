#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[1114514];
int main(){
	ll n,ma=0;
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		cnt[x]++;
		ma=max(ma,x);
	}
	ll ans=0;
	for(int i=1;i<=ma;i++){
		if(cnt[i]){
			if(cnt[i]==1)ans++;
			for(int j=2*i;j<=ma;j+=i)cnt[j]=0;
		}
	}
	cout<<ans;
	return 0;
}