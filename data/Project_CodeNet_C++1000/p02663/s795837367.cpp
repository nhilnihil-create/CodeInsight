#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int h1, m1;
  cin >> h1 >> m1;
  int h2, m2;
  cin >> h2 >> m2;
  int k;
  cin >> k;
  m1 += h1*60;
  m2 += h2*60;
  int d = m2 - m1;
  if(d < k) cout << 0 << endl;
  else cout << d - k << endl;
  return 0;
}