#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int x[20][20];
	int n,m,c,d,e;
	bool dame[20][20];
	while(true){
		memset(x,0,sizeof(x));
		memset(dame,false,sizeof(dame));
		cin>>n>>m;
		if(n==0 && m==0){
			break;
		}
		cin>>c;
		for(int i=0;i<c;i++){
			cin>>d>>e;
			dame[d][e]=true;
		}
		for(int i=1;i<=n;i++){
			if(dame[i][1]==true){
				for(int j=i;j<=n;j++){
					x[j][1]=0;	
				}
				goto Exit1;
			}
			else{
				x[i][1]=1;
			}
		}
		Exit1:;
		for(int i=1;i<=m;i++){
			if(dame[1][i]==true){
				for(int j=i;j<=n;j++){
					x[1][j]=0;	
				}
				goto Exit2;
			}
			else{
				x[1][i]=1;
			}
		}
		Exit2:;
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				if(dame[i][j]==true){
					x[i][j]=0;
				}
				else{
					x[i][j]=x[i-1][j]+x[i][j-1];
				}
			}
		}
		cout<<x[n][m]<<endl;
	}
	return 0;
}