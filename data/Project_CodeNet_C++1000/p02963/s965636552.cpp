#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
int main() {
  ll s;
  cin >> s;
  ll s2 = sqrt(s);
  ll x1=1, y1, x2=e9, y2;
  y2 = s/e9;
  if(y2!=e9)y2++;
  y1 = x2*y2-s;
  
  cout << 0 << " " << 0 << " " <<  x1 << " " << y2 << " " << x2 << " " << y1 << endl;
}