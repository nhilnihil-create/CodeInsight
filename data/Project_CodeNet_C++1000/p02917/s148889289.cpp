#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  int a[n], b[n - 1];
  int ans = 0;
  rep(i, n - 1) cin >> b[i];
  if(n == 1) cout << b[0] * 2 << endl;
  else{
    a[0] = b[0];
    rep(i, n - 1){
      if(i == n - 2) a[i + 1] = b[i];
      else a[i + 1] = min(b[i], b[i + 1]);
    }
    ll sum = 0;
    rep(i, n) sum += a[i];
    cout << sum << endl;
  }


  return 0;
}