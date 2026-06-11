#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
   int n;
   cin >> n;
   
   vector<pair<string,int>> st(n);
   rep(i,n)
   {
      cin >> st[i].first>>st[i].second;
   }
   string s;
   cin >> s;
   int ans = 0;
   bool is = false;
   rep(i,n)
   {

      if(is)
      {
         ans += st[i].second;
      }
      if(st[i].first==s)is= true;
   }
   cout<<ans<<endl;
   return 0;
}