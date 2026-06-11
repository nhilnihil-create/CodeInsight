
      #include<bits/stdc++.h>
      using namespace std;


      int main()
      {


           ios_base::sync_with_stdio(false);
           cin.tie(NULL);
         /* #ifndef ONLINE_JUDGE
              freopen("input.txt","r",stdin);
              freopen("output.txt","w",stdout);
          #endif*/
      map<string,int>nish;
      int count;
      cin>>count;
      for(int i=0;i<count;i++)
      {
        string temp;
        cin>>temp;
        sort(temp.begin(),temp.end());
        nish[temp]++;
      }

      long long int ans=0;
      for(auto it:nish)
      {
        long long int total=it.second;
        total=(1LL*total*(total-1))/2;

        ans+=total;
      }

      cout<<ans<<endl;
      return 0;


      }