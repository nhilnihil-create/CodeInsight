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
bool mywish(const pii &a,const pii &b)
  {
    return a.first > b.first;
  }
int power(int base,int n,int m)
 {
  if(n == 0)
     return 1;
  if(n&1)
     {
      int y = power(base,n-1,m);
      return (y*base)%m;
     }
  else
     {
      int y = power(base,n/2,m);
      return (y*y)%m;
     }
 }

void solve()
  {
   int n,m;
   cin>>n>>m;
   vector<int> v(n);
   int lcm = 1;
   int p2 = -1;
   loop(i,0,n)
    { 
     cin>>v[i];
     int x = v[i];
     lcm = lcm*v[i]/__gcd(v[i],lcm);
     int temp = 0;
     while(x%2==0)
       {
        x/=2;
        temp++;
       }
     if(p2 == -1)
       p2 = temp;
     else if(p2 != temp)
       p2 = -2;
    }
  if(p2 == -2)
     {
      cout<<0;
      return;
     }
  int mx = 2*m/lcm;
  int count = ceil(1.0*mx/2);
  cerr<<lcm<<END;
  cout<<count;
  }
signed main()
 {
  
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
}    
