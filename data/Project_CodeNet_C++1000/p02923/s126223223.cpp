#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"







int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n;
   cin>>n;
   vector<int>v(n);
   f(n)cin>>v[i];
   //reverse(v.begin(),v.end());
   vector<int> dp(n+1,0);
   dp[0]=0;
   dp[1]=1;
     int answer=1;
   for(int i=2;i<=n;i++)
   {
       if(v[i-1]<=v[i-2]) dp[i]=dp[i-1]+1;
       else dp[i]=1;

       answer=max(dp[i],answer);


   }


   cout<<answer-1<<endl;






}