#include<iostream>
#include<cstring>
#include<cstdio> 
#define INF 0x3f3f3f3f
 
using namespace std;
 
const int N=25;
int c[N];
int n,m,x;
int a[N][N];
int ans=INF;
int main()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<(1<<n);i++){
		int sum=0; 
		int res[N]; 
		memset(res,0,sizeof(res));
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				for(int k=1;k<=m;k++){
					res[k]+=a[j+1][k];
				}
				sum+=c[j+1];
			}
		}
		bool flag=0;
		for(int j=1;j<=m;j++){
			if(res[j]<x){
				flag=1;
				break;
			}
		}
		if(!flag) ans=min(sum,ans);
	}
	if(ans==INF) puts("-1");
	else cout<<ans<<endl;	
	return 0;
}
