#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = (a); i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  ll a; double b;
  cin >> a >> b;
  // .99999みたいな時に切り捨て型変換が行われてしまうから+0.5で補正
  int bb = b*100+0.5;
  ll ans = a*bb;
  printf("%lld\n",ans/100);
  return 0;
}