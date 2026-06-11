#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pc __builtin_popcount

const int mod = 1e9+7;
int ar[2005];
int before[2005];
int after[2005];
int n,k;

int mult(int n,int m){
	if(n>m){
		swap(n,m);
	}
	if(n==0 || m==0){
		return 0;
	}
	if(m==1){
		return n;
	}
	int k = mult(n,m/2);
	int ans = k+k;
	ans %= mod;
	if(m&1){
		ans += n;
	}
	ans %= mod;
	return ans;
}

int32_t main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			before[i]+=(ar[i]>ar[j]);
		}
		for(int j=i+1;j<=n;j++){
			after[i]+=(ar[i]>ar[j]);
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans += after[i]*k;
		ans %= mod;
		ans += mult(((k)*(k-1)/2),(before[i]+after[i]));
		ans %= mod;
		//cout<<ans<<"\n";
	}
	/*for(int i=1;i<=n;i++){
		cout<<before[i]<<" "<<after[i]<<"\n";
	}*/
	cout<<ans;
}
