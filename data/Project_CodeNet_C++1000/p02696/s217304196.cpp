#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  ll a,b,n,x,ans;
  cin >> a >> b>> n;
  x = n;
  if (n >= b - 1) x = b - 1;
  ans = a*(x%b)/b;
  cout << ans <<endl;
}
