#include<bits/stdc++.h>
#define mod 1000000009
#define int long long
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
	 int l,r,d;
	 cin>>l>>r>>d;
	 int re=0;
	 for(int i=l;i<=r;i++){
		 if(!(i%d))
		 re++;
	 }
	 cout<<re;

}