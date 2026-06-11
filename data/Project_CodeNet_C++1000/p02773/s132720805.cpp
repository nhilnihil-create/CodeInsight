#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main()
{


      int t;
      cin>>t;
      while(t--)
      {
         string s;
         cin>>s;
         mp[s]++;
      }

      int maxi=0;
      for(auto i:mp)
      {
        maxi=max(maxi,i.second);
      }

      for(auto i:mp)
      {
        if(i.second==maxi)
          cout<<i.first<<endl;
      }

}
