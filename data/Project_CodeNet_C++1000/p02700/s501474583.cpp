#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define bug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 9223372036854775807ll;

void solve()
  {
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   bool turn = 0;
   while(1)
     {
      if(!turn)
         {
           c -= b;
           if(c <= 0)
             {
              cout<<"Yes";
              return;
             }
           turn = 1;
         }
      else
         {
          a -= d;
          if(a <= 0)
             {
              cout<<"No";
              return;
             }
          turn = 0;
         }
     }
  }
signed main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
   /*int t;
   cin>>t;
   while(t--)*/
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 