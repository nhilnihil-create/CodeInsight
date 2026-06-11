#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
  ll k, q;
  cin >> k >> q;

  vector<ll> d(k);
  for(ll i = 0; i < k; i++) {
    cin >> d[i];
  }

  for(ll i = 0; i < q; i++) {
    ll n, x, m;
    cin >> n >> x >> m;

    ll sub = 0;
    vector<ll> D(k);

    ll S = 0;
    for(ll j = 0; j < k; j++) {
      D[j] = d[j] % m;
      S += D[j];
      if(D[j] == 0) {
        sub++;
      }
    }
    
    S += S * ((n-1)/k - 1);
    sub *= (n-1)/k;
    for(ll j = 0; j < (n-1) % k; j++) {
      S += D[j];
      if(D[j] == 0) {
        sub++;
      }
    }

    ll y = x + S;
    sub += (y / m) - (x / m);
 
    cout << n-1-sub << endl;
  } 

  return 0;
}