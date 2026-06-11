#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[214514],b[214514];
int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		b[i]+=b[i-1];
	}
	ll now=m,ans=0;
	for(int i=0;i<=n;i++){
		for(int j=now;j>=0;j--){
				if(a[i]+b[j]<=k){
					now=j;
					ans=max(ans,i+now);
					break;
				}
		}
	}
	cout<<ans<<endl;
	return 0;
}
