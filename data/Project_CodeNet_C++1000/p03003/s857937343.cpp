#include<iostream>
using namespace std;
int a[2001],b[2001],f[2001][2001];
const int mod=1000000007;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
		for(int j=1;j<=m;j++){
		cin>>b[j];
	} 
	for(int i=0;i<=n;i++){
		f[i][0]=1;
	}
		for(int j=1;j<=m;j++){
		f[0][j]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=((long long)f[i-1][j]+f[i][j-1]-f[i-1][j-1]+mod)%mod;
			if(a[i]==b[j]){
				f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
			}
		}
	}
	
	cout<<f[n][m]<<endl;
} 