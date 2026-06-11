#include<bits/stdc++.h>
using namespace std;
long long a[305],d[303][303];
int main(){
	long long n,m,ans=2e17;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			d[i][j]=2e17;
		}
	}
	for(int i=1;i<=n;i++){
		d[i][1]=a[i];
	}
	d[0][0]=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<=i;k++){
				d[i][k]=min(d[i][k],d[j][k-1]+max((long long)0,a[i]-a[j]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=min(d[i][n-m],ans);
	}
	cout<<ans<<endl;
}