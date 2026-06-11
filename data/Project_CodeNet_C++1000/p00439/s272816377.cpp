#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;

int main(){
	int n,k;
	while(1){
		cin>>n>>k;ll a[n],s[n+1]={0};
		if(n==0&&k==0) break;
		for(int i=0;i<n;i++){
			cin>>a[i];
			s[i+1]=s[i]+a[i];
		}
		ll ans=0;
		for(int i=0;i<=n-k;i++){
			ans=max(ans,s[i+k]-s[i]);
		}
		cout<<ans<<endl;
	}
}
