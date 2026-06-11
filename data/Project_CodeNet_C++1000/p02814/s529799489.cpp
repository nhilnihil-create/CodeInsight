#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, m;
  cin >> n >> m;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  

  set<ll> b;
  ll tt = 0;
  for (ll i = 0; i < n; i++){
    ll t = 0;
    while (a[i] % 2 == 0){
      a[i] /= 2;
      t++;
    }
    b.insert(t);
    tt = t;
  }

  if (b.size() > 1){
    cout << 0 << endl;
  }
  else {
    ll l = (1LL << (tt-1));
    for (ll i = 0; i < n; i++){
      l = lcm(l, a[i]);
    }
    cout << (m / l + 1) / 2 << endl;
  }

  return 0;
}
