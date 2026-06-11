#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll A,B,C,D; cin >>A>>B>>C>>D;
  ll c = B/C - (A-1)/C;
  ll d = B/D - (A-1)/D;
  ll cdl = lcm(C,D);
  //cerr << "cdl: " << cdl <<endl;
  ll cd = B/(cdl) - (A-1)/(cdl);
  //cerr << c <<" " << d <<endl;
  
  ll ans = (B-A+1) - c- d + cd;
  cout << ans << endl;
}
