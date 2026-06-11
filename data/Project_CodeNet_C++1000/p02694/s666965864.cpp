#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll X;
  cin >> X;

  int ans = 0;
  ll mon = 100;
  
  while(mon < X){
    mon += mon/100;
    ans++;
  }
  cout << ans << endl;
  return 0;
}