#include<bits/stdc++.h>
#define mod 1000000000000000000
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
int n,m;
cin>>n>>m;
int ans=0;
int a[n];
for(int i=0;i<n;i++){
	cin>>a[i];
	ans+=a[i];
}
int x=0;
for(int i=0;i<n;i++){
	double d=(double)(1/(4*(double)m));
	d*=ans;
	if(d>a[i])
	continue;
	x++;
}
if(x>=m)
cout<<"Yes";
else
cout<<"No";

}