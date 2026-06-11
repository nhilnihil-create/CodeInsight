#include<bits/stdc++.h>
#define int long long   
#define mod 1000000009
#define garou ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int pow(int p,int r){
	int ans=1;
	while(r>0){
     if(r&1){
		 ans=((ans%mod)*(p%mod))%mod;
	 }
	 r=r>>1;
     p=((p%mod)*(p%mod))%mod;
	}
	return ans;
}
signed main() {
	garou;
    int a,b,n;
	cin>>a>>b>>n;
	cout<<(a*min(b-1,n))/b;
}
