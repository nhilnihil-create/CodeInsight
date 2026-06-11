#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main() {
   int n;
   cin>>n;
   int dp[n];
   int arr[n];
   for(int i=0;i<n;i++)
   cin>>arr[i];
   dp[n-1]=1;
   int maxi=1;
   for(int i=n-2;i>=0;i--)
   {
       if(arr[i]>=arr[i+1])
       dp[i]=1+dp[i+1];
       else dp[i]=1;
       maxi=max(maxi,dp[i]);
   }
   cout<<maxi-1<<endl;
   
}