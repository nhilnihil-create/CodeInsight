#include <bits/stdc++.h>
using namespace std;
int a[50][50],c[50],sum[50],ans=INT_MAX;
bool f=0;
int main(){
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	for(int i=0;i<(1<<n);++i){
		memset(sum,0,sizeof(sum)); 
		int cost=0;
		for(int j=0;j<n;++j){
			if(i&(1<<j)){
				cost+=c[j+1];
				for(int k=1;k<=m;++k)sum[k]+=a[j+1][k];
			}
		}
		f=0;
		for(int k=1;k<=m;++k){
			if(sum[k]<x)f=1;
		}
		if(f)continue;
		ans=min(ans,cost);
//		cout<<i<<":";
//		cout<<cost<<" ";
//		for(int k=1;k<=m;++k)cout<<sum[k]<<' ';
//		cout<<endl;
	}
	if(ans==INT_MAX)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}