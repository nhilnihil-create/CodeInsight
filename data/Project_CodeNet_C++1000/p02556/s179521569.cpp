#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;

  ll w_min = inf;
  ll w_max = -inf;
  ll z_min = inf;
  ll z_max = -inf;
  
  rep(i,n){
    ll x,y;
    cin >> x >> y;
    ll z = x - y;
    ll w = x + y;
    w_min = min(w_min,w);
    w_max = max(w_max,w);
    z_min = min(z_min,z);
    z_max = max(z_max,z);
  }
  cout << max(z_max-z_min, w_max-w_min) << endl;
}
