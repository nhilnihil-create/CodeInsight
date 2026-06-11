#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define YUGEN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lp(i,start,end) for(int i=start;i<end;i++)
#define MAX 105
#define BPC(x)  __builtin_popcountll(x)
#define test() ll t; cin>>t; while(t--)
#define gcd(a,b)  __gcd(a,b)
#define SIZE 26
ll gcd(ll a,ll b) {if (a==0) return b;return gcd(b%a,a);}

int main()
 {
    YUGEN;
      // test()
      // {
        // ll a,b;
       // cin>>a>>b;
       // ll ans=0;
        //if(a<b)
        //{
         //  int x=(b-a);
         //  if(x&1)
        //   ans++;
        //   else
        //   ans+=2;
       // }
      //   else if(a==b)
      //   ans=0;
      //   else if(a>b)
      //   {
      //     int x=(a-b);
      //     if(x&1)
      //     ans+=2;
      //     else
      //     ans++;
          
      //   }
      //   cout<<ans<<endl;
      // }
      string s;
      cin>>s;
      string t;
      cin>>t;
      int ans=t.size();
      for(int i=0;i<=s.size()-t.size();i++)
      {
        int count=0;
        for(int j=0;j<t.size();j++)
        {
          if(t[j]!=s[i+j])
          count++;
        }
        ans=min(ans,count);
      }
      cout<<ans;
 }


