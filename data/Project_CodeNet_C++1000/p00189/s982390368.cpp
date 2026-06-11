#include<iostream>
#include<stdio.h>
#include<cmath>
#define INF 9999999
using namespace std;
int n,t[10][10],a,b,c,d,flg[10],sum,mini,miniNo;
int main(){
	while(1){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				t[i][j]=INF*(j!=i);
			}
			flg[i]=0;
		}
		cin>>n;
		if(n==0)break;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			t[a][b]=t[b][a]=c;
			flg[a]=flg[b]=1;
		}
		for(int k=0;k<10;k++){
			for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
					t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
				}
			}
		}
		mini=INF;
		for(int i=0;i<10;i++){
			if(flg[i]){
				sum=0;
				for(int j=0;j<10;j++){
					if(t[i][j]!=INF){
						sum+=t[i][j];
					}
				}
				if(mini>sum){
					mini=sum;
					miniNo=i;
				}
			}
		}
		cout<<miniNo<<" "<<mini<<endl;

	}
			return 0;
}