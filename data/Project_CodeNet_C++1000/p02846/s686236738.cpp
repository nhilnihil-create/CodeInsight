#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int t1,t2;ll a1,a2,b1,b2,p,q;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  p = (a1-b1)*t1;q = (a2-b2)*t2;
  if(p > 0){p *= -1;q *= -1;}
  if(p+q < 0){cout << 0 << endl;return 0;}
  else if(p+q == 0){cout << "infinity" << endl;return 0;}
  else{
    ll s = -p/(p+q),t = (-p)%(p+q);
    if(t != 0) cout << s*2+1 << endl;
    else cout << s*2 << endl;
  }
}