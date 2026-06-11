#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;


ll pow5[4001];
ll calc(ll a, ll b) {
  if (a<0) {
    if (b<0){
      return -pow5[-a]+pow5[-b];
    } else{
      return -pow5[-a]-pow5[b];
    }
  } else {
    if (b<0){
      return pow5[a]+pow5[-b];
    } else{
      return pow5[a]-pow5[b];
    }
  }
}

int main() {
  ll X;
  cin >> X;
  for (ll i = 0; i <= 4000; i++) {
    pow5[i] = i*i*i*i*i;
  }
  for (ll i=-4000; i<=4000; i++) {
    for (ll j=-4000; j<=4000; j++) {
      if(calc(i,j) == X) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
}

