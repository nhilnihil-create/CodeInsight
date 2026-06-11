#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,count=0;
      string s;
      cin>>s;
      for(i=0;i<s.size();i++)
      {
          if(i%2==0)
          {

              if(s[i]=='R' || s[i]=='U' || s[i]=='D')
              {
                 // cout<<s[i];
                  count++;
              }
          }
          else{
            if(s[i]=='L' || s[i]=='U' || s[i]=='D')
                count++;
          }
      }
      //cout<<count<<" "<<s.size();
      if(count==s.size())
      {
          cout<<"Yes";
      }
      else
        cout<<"No";
}
