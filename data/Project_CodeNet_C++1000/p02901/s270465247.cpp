
#include<bits/stdc++.h>
using namespace std;



int main()
{


     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   */
    int n,m;
    cin>>n>>m;
    vector<long long int>dp((1<<n),INT_MAX);
    dp[0]=0;
    while(m--)
    {
      int a,b;
      cin>>a>>b;
      int t=0;
      while(b--)
      {
        int num;
        cin>>num;
        t|=(1<<(num-1));
      }

      auto ndp=dp;
      for(int i=0;i<(1<<n);i++)
      {
        if(dp[i]<INT_MAX)
        {
          ndp[(i|t)]=min(ndp[(i|t)],dp[i]+a);
        }
      }

      swap(dp,ndp);
    }

    if(dp.back()<INT_MAX)
    cout<<dp.back()<<endl;
    else
    cout<<"-1"<<endl;  

       return 0;
    
}