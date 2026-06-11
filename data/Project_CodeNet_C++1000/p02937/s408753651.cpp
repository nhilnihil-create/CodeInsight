#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define trace(x) cerr<<x<<END;
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = INT_MAX;


void solve()
  {
    string s,t;
    cin>>s>>t;
    map<char,set<int>> mp;
    int sz = s.size();
    loop(i,0,sz)
      mp[s[i]].insert(i+1);
    int last = 0,ans = 0;
    int n = t.size();
    loop(i,0,n)
     {
      //cerr<<ans<<" "<<last<<END;
      if(mp[t[i]].empty())
         {
          cout<<-1;
          return;
         }
      auto it = mp[t[i]].upper_bound(last);
      if(it == mp[t[i]].end())
         {
          ans += sz + *mp[t[i]].begin() - last;
          last = *mp[t[i]].begin();
         }
      else
         {
          ans += *it - last;
          last = *it;
         }
     }
      //cerr<<ans<<" "<<last<<END;

    cout<<ans;
  } 
signed main()
 {
  
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 