#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int v[n];
  rep(i,n) cin >> v[i];
  
  sort(v,v+n);
  
  ld ans = (v[0] + v[1]) / 2.0; 
  for(int i = 2; i < n; i++)
  {
    ans = (long double)( (ans + v[i]) / 2.0 );
  }
  
  cout << fixed;
  cout << setprecision(20);
  cout << ans << endl;
  
}