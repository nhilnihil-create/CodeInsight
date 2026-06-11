#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  ll x,ans=0;
  cin >> x;
  ans = (x/500)*1000 + x%500/5*5;
  cout << ans << endl;
  return 0;
}