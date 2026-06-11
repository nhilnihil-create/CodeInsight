#include <bits/stdc++.h>

using namespace std;
const int mod = 1000000007;

int main()
{
    int n ;
    
    cin>>n;
   vector< long long>dp(2001);
   dp[0]=1;
   for(int i =0;i<=2000;i++)
   for(int j =0;j<=i-3;j++)
   {
       dp[i]+=dp[j];
       dp[i]=dp[i]%mod;
   }
cout<<dp[n];
    return 0;
}
