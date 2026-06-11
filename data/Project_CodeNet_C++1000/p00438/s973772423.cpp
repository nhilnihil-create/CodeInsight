#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>


using namespace std;

int main (void){

	int width;
	int height;

	int dp[32][32];
	bool status[32][32];
	int n;
	int nx,ny;

	while(true){
		scanf("%d%d",&width,&height);
		if((width==0)||(height==0))break;

		for(int i=0;i<32;i++){
			for(int j=0;j<32;j++){
				dp[i][j] = 0;
				status[i][j] = false;
			}
		}
		dp[1][1] = 1;

		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&nx,&ny);
			status[nx][ny] = true;
		}

		for(int i=1;i<=width;i++){
			for(int j=1;j<=height;j++){
				if(!status[i][j]){
					dp[i][j] += dp[i-1][j] + dp[i][j-1]; 
				}
			}
		}

		printf("%d\n",dp[width][height]);

	}



	return 0;
}