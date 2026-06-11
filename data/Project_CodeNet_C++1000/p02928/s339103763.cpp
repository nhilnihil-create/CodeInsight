#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
#define mod 1000000007
int n,k;
int arr[N];
int pre[N],sum[N];
map<int,int> vis,mp;
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
	mp[arr[n]]++;
	int ans=0;
	for(int i=n-1;i>=1;i--){
		int tot=0;
		for(int j=1;j<arr[i];j++){
			tot+=mp[j]; 
		}
		pre[i]=tot;
		mp[arr[i]]++;
	}
	for(int i=1;i<=n;i++){
		int tot=0;
		for(int j=1;j<arr[i];j++){
			tot+=mp[j];
		}
		sum[i]=tot;
	}
	int temp;
	temp=(k-1)*k/2;
	//temp-=k;
	temp%=1000000007;
	for(int i=1;i<=n;i++){
		int b=sum[i];
		int a=pre[i];
		ans+=(((k)*a)%mod+(b*(temp)%mod+mod)%mod)%mod;
		ans=ans%mod;
	}
	cout<<ans;
	return 0;
}