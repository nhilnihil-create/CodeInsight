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
const int inf = 9223372036854775807ll;
const int nax = 2005;
int a[nax];
map<tuple<int,int,int>,int> mp;
int n;
void solve()
  {
     cin>>n;
     loop(i,0,n)
      {
        cin>>a[i];
        //mp[a[i]]++;
      }
     int cnt = 0;
     sort(a,a+n);
     loop(i,0,n)
      {
        loop(j,i+1,n)
         {
          loop(k,j+1,n)
            {
              if(a[i] < a[j] + a[k] && a[j] < a[i] + a[k] && a[k] < a[j] + a[i] )
              {
                 cnt++;
                /*mp[{i,j,k}]++;
                mp[{j,i,k}]++;
                mp[{i,k,j}]++;
                mp[{j,k,i}]++;
                mp[{k,i,j}]++;
                mp[{k,j,i}]++;*/
              }
            }
         }
      }
   /* for(auto x : mp)
       cerr<<get<0>(x.ff)<<" "<<get<1>(x.ff)<<" "<<get<2>(x.ff)<<END;
    cout<<cnt<<" ";*/
    cout<<cnt;
  }
signed main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 