#include <bits/stdc++.h>
#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

using namespace atcoder;
using namespace std;

int main(void){
  ll n, q;
  cin >> n >> q;
  
  fenwick_tree<ll> fw(n);
  for (int i = 0; i < n; i++){
    ll a;
    cin >> a;
    
    fw.add(i, a);
  }

  for (int i = 0; i < q; i++){
    ll c, p, x;
    cin >> c >> p >> x;
    
    if (c){
      cout << fw.sum(p, x) << endl;
    }
    else
      fw.add(p, x);
  }

  return 0;
}
