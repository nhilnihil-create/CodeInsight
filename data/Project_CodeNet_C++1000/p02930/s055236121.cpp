#include<bits/stdc++.h>
using namespace std;

int n,g[505][505];
int col[505];
void go(int len,int z){
	int st=1;
	while(1){
		for(int i=st;i<st+len*2;i++){
			if(i<st+len)col[i]=1;
			else col[i]=0;
			if(i>n)break;
		}
		st+=len*2;if(st>n)break;
	}
//	cerr<<z<<endl;
//	for(int i=1;i<=n;i++)cerr<<col[i]<<" ";cerr<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(col[i]!=col[j]&&g[i][j]==-1){
				g[i][j]=z;
			}
		}
	}
}

int main(){
	memset(g,-1,sizeof g);
	cin>>n;
	int Maxlvl=0;
	while((1<<Maxlvl)<n)Maxlvl++;
	cerr<<Maxlvl<<endl;
	for(int i=1;i<=Maxlvl;i++){
		go(1<<i-1,i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}