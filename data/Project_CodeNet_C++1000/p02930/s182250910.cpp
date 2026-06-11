#include <bits/stdc++.h>

using namespace std;

int n;
int g[510][510];
int lvl;

int main(){
	scanf("%d",&n);
	lvl=1;
	for(int k=1;k<=n;k<<=1){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(g[i][j]==0 && (i&k)!=(j&k)){
					g[i][j]=lvl;
				}
			}
		}
		lvl++;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			printf("%d",g[i][j]);
			if(j!=n)printf(" ");
		}
		printf("\n");
	}
	return 0;
}