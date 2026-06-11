#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  double w,h,x,y; cin >>w>>h>>x>>y;
  cout << fixed << setprecision(10);
  cout << w*h/2 << " ";
  
  if(x == w/2 && y == h/2)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}