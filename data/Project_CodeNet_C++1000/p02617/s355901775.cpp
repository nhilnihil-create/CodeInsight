#include<bits/stdc++.h>
#define rep(i, x) for (ll i = 0; i < (x); i++)
#define chmax(x, a)  do { x = max(x, a); } while(0)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


int main(void) {
  ll N;
  cin >> N;
  ll V = 0, E = 0;
  rep(i, N) {
    V += (i + 1) * (N - i);
  }
  rep(i, N-1) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    E += (u + 1) * (N - v);
  }
  cout << (V - E) << endl;
  return 0;
}
