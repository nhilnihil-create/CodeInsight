#include<iostream>
using namespace std;
const int N=2e3+10;
int x[N][N],y[N][N];
string a[N];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j-1]=='#') continue;
			x[i][j]=x[i-1][j]+1;
			y[i][j]=y[i][j-1]+1;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(a[i][j-1]=='#') continue;
			x[i-1][j]=max(x[i-1][j],x[i][j]);
			y[i][j-1]=max(y[i][j-1],y[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans=max(x[i][j]+y[i][j]-1,ans);
		}
	}
	cout<<ans;
	return 0;
}
