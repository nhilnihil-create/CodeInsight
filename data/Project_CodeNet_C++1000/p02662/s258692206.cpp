#include<iostream>
using namespace std;

typedef long long ll;
ll a[10005];
ll dp[10005]={0};
ll mod=998244353;

int main()
{
	ll n,s;
	cin>>n>>s;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		for(ll j=s;j>=0;j--){
			dp[j]=(dp[j]*2)%mod;
			if(j>=a[i]){
				dp[j]=(dp[j]+dp[j-a[i]])%mod;
			}
			if(j==a[i]){
				dp[j]=(dp[j]+1)%mod;
			}
			if(j==0){
				dp[j]=(dp[j]+1)%mod;
			}
		}
	}
	cout<<dp[s]<<endl;
	return 0;
}