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
    int n,m,qe;
	cin>>n>>m>>qe;
	int a[qe][4];
	for(int i=0;i<qe;i++){
    cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
	}
	int mx=-1;
	for(int i=1;i<=m;i++)
	for(int j=i;j<=m;j++)
	for(int k=j;k<=m;k++)
	for(int l=k;l<=m;l++)
	for(int o=l;o<=m;o++)
	for(int p=o;p<=m;p++)
	for(int z=p;z<=m;z++)
	for(int q=z;q<=m;q++)
	for(int u=q;u<=m;u++)
	for(int t=u;t<=m;t++){
		int arr[10]={i,j,k,l,o,p,z,q,u,t};
        int b=0;
		for(int x=0;x<qe;x++){
			if(arr[a[x][1]-1]-arr[a[x][0]-1]==a[x][2])
			b+=a[x][3];
		}
		mx=max(mx,b);
	}
	cout<<mx;
}