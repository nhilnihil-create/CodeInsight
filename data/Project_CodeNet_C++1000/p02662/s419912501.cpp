#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define ff first
#define ss second

int mod = 998244353;


int power(int x, int y, int p)  
{  
    int res = 1;      
  
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
   
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  


main(){
	int n,s;
	cin>>n>>s;
	int arr[n+1],i,j,k;
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}
	int dp[n+1][s+1];
	for(i=0;i<n+1;i++){
		for(j=0;j<s+1;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1;
	
	int count=0;
	for(i=1;i<=n;i++){
		for(j=0;j<=s;j++){
			dp[i][j] = dp[i-1][j]*2;
			dp[i][j] = dp[i][j]%mod;
			if(arr[i]<=j){
				dp[i][j] += dp[i-1][j-arr[i]];
				dp[i][j] = dp[i][j]%mod;
			}
		}
	}
	// for(i=0;i<=n;i++){
	// 	for(j=0;j<=s;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<dp[n][s]<<endl;
	return 0;
}