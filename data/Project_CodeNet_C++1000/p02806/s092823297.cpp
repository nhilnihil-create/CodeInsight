#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;

struct st
{
   string s;
   int t;
   /* data */
};


int main()
{
   int n;
   cin >> n;
   vector<st> list(n);
   rep(i,n)
   {
      int a;
      string b;
      cin >> b;
      cin >> a;
      
      list[i].s=b;
      list[i].t=a;
   }
   string now;cin >> now;
   
   bool hoge =false;
   int ans = 0;
   rep(i,n)
   {
      
      if(hoge)ans += list[i].t;
      if(list[i].s==now)
      {
         hoge=true;
      }
   }
   cout<<ans<<endl;
   return 0;
}