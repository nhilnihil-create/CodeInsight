#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
  	cin >>n;
  	long int p[n+1];
  	rep(i,n){
    	cin >>p[i]>>p[i+1];    
    }
  	long int dp[n+1][n+1];
  	for(int i=1;i<=n;i++){
    	dp[i][i]=0;
    }
  	
  	for(int l=1;l<=n-1;l++){
    	for(int i=1;i<=n-l;i++){
        	int j=i+l;
          	dp[i][j]=1000000000;
            for(int k=i;k<=j;k++){
              long int x=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
             dp[i][j]=min(dp[i][j],x);    	
        	}             
            
        }
    }
  	cout<<dp[1][n]<<endl;
  
}



