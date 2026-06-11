#include <bits/stdc++.h>
using namespace std;
long long int mod =  1e9 + 7;
int main() {
  long long int n,m;
  cin>>n>>m;
  long long int arr[n];
 long long int brr[m];
  for(int i = 0;i<n;i++)
  {
      cin>>arr[i];
  }
    for(int i = 0;i<m;i++)
  {
      cin>>brr[i];
  }
 long long int dp[n+1][m+1];
for(int i = 0 ;i <=n; i++ )
{
    for(int j = 0;j<=m;j++)
    {
        if(i==0 || j==0)
        {
            dp[i][j] = 1;
        }else
        {
               if(arr[i-1]==brr[j-1])
               {
                   dp[i][j] = (dp[i][j-1] + dp[i-1][j] + mod)%mod;
               } else{
                   dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] +mod)%mod;
               }

        }

    }

}
cout<<dp[n][m];


}
