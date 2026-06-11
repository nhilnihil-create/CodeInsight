#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define endl        "\n"
#define mod         2019

map<int,int>m;
int main()
{
   string s;
   cin>>s;
   m[0]=1;
   int sum=0, ten=1;
   ll ans=0;

  for(int i=s.size()-1;i>=0;i--)
   {
       int d=s[i]-'0';
       sum=(sum+(d*ten))%mod  ;
       ten=(ten*10)%mod;
       ans+=m[sum];
        m[sum]++;

        //cout<<sum<<endl;

   }

   cout<<ans<<endl;
}






