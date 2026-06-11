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
const int inf = 2e18;  
const int mod1 = 998244353;
const int mod = 1e9 + 7;
const int nax = 100005;
int x,y,A,B,C,a[nax],b[nax],c[nax];

void solve()
 {
  cin>>x>>y>>A>>B>>C;
  loop(i,1,A+1)
   cin>>a[i];
  loop(i,1,B+1)
   cin>>b[i];
  loop(i,1,C+1)
   cin>>c[i];
  sort(a+1,a+A+1,greater<int>());
  sort(b+1,b+B+1,greater<int>());
  sort(c+1,c+C+1,greater<int>());
  multiset<int> red,green;
  int r = 0,g = 0;
  loop(i,1,x+1)
  {
    r += a[i];
    red.insert(a[i]);
  }
  loop(i,1,y+1)
  {
    g += b[i];
    green.insert(b[i]);
  }
  int pos = 1;
  while(pos<=C)
     {
      int red_least = *(red.begin());
      int green_least = *(green.begin());
      if((c[pos]>red_least && c[pos]<green_least) || (c[pos]>red_least && c[pos]>green_least && red_least <= green_least))
         {
          red.erase(red.begin());
          r -= red_least;
          red.insert(c[pos]);
          r += c[pos];
          pos++;
         }
      else if((c[pos]<red_least && c[pos]>green_least) || (c[pos]>red_least && c[pos]>green_least && red_least > green_least))
         {
          green.erase(green.begin());
          g -= green_least;
          green.insert(c[pos]);
          g += c[pos];
          pos++;
         }
      else 
         break;
     }
  cout<<r+g;
 }
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
  solve();
  // cerr<<END<<1.0*clock()/CLOCKS_PER_SEC;
  return 0;
} 