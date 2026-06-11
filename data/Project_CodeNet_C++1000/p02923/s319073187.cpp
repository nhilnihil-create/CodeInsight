/*
 Author:Alokit Kumar
   */
  #include<bits/stdc++.h>
  using namespace std;
  #define int long long 
  int32_t main()
  {
   int n,i,j,k,l;
   cin>>n;
   int a[n+1];
   for(i=1;i<=n;i++) cin>>a[i];
   int dp[n+1];dp[n]=0;
   for(i=n-1;i>=1;i--)
   {
     if(a[i]>=a[i+1])
      dp[i]=dp[i+1]+1;
     else
      dp[i]=0;
   }
   int min1=0;
   for(i=1;i<=n;i++)
    min1=max(min1,dp[i]);
    cout<<min1;
  }