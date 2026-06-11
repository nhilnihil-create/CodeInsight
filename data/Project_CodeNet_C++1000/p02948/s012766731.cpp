
      #include<bits/stdc++.h>
      using namespace std;




  

    int dp[100005];

    void solve()
    {
      for(int i=0;i<100005;i++)
      {
        dp[i]=i;
      }
    }


    int sol(int index)
    {
      if(index<=-1) return -1;
      if(dp[index]==index)return index;
      else
        return dp[index]=sol(dp[index]);
    }


      int main()
      {


           ios_base::sync_with_stdio(false);
           cin.tie(NULL);
          /*#ifndef ONLINE_JUDGE
              freopen("input.txt","r",stdin);
              freopen("output.txt","w",stdout);
          #endif*/
      solve();
      int n,m;
      cin>>n>>m;
      vector<pair<int,int>>nish;

      for(int i=0;i<n;i++)
      {
        int first,second;
        cin>>first>>second;
        nish.push_back({second,first});
      }
      sort(nish.begin(),nish.end());



      long long int ans=0;
    for(int i=n-1;i>=0;i--)
    {
      int start=sol(m-nish[i].second);
     // cout<<start<<" "<<nish[i].first<<" "<<nish[i].second<<endl;
      if(start!=-1)
      {
        ans+=nish[i].first;
        dp[start]=start-1;
      }

    }

    cout<<ans<<endl;
    return 0;


    }