#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, m;
  cin >> n;
  m = n + 1;
  int a[m], b[n];
  rep(i, m) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll ans = 0;
  rep(i, n) {
    if(b[i] <= a[i]){
      ans += b[i];
    }
    else{
      ans += a[i];
      b[i] -= a[i];
      if(b[i] <= a[i + 1]){
        ans += b[i];
        a[i + 1] -= b[i];
      }
      else{
        ans += a[i + 1];
        a[i + 1] = 0;
      }
    }
    //cout << b[i] << " " << a[i] << endl;
  }
  cout << ans << endl;


    
  
  return 0;
}
