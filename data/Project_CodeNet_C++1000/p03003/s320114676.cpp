#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2005],b[2005],d[2005][2005],mod=1e9+7;
int main(){
	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=2;i<=n+1;i++){
		cin>>a[i];
	}
	for(int i=2;i<=m+1;i++){
		cin>>b[i];
	}
	d[1][1]=1;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m+1;j++){
			d[i][j]=(d[i][j]%mod+d[i][j-1]%mod+d[i-1][j]%mod-d[i-1][j-1]%mod)%mod;
			if(a[i]==b[j]) d[i][j]=(d[i][j]%mod+d[i-1][j-1]%mod)%mod;
		}
	}
	cout<<(d[n+1][m+1]%mod+mod)%mod<<endl;
}