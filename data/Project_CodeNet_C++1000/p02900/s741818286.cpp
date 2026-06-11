#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////
const ll inf = 1LL<<60;

ll gcd(ll a, ll b){return b==0 ? a : gcd(b, a%b);}

map<ll, ll> prime_factor(ll n)
{
  map<ll, ll> res;
  for (ll i=2; i*i<=n; i++) {
    while (n%i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

int main()
{
  ll a,b; cin>>a>>b;
  ll g = gcd(a,b);
  map<ll, ll> mp = prime_factor(g);

  ll ans = 1;
  for (auto v:mp) {
    if (v.second > 0) ans++;
  }
  cout << ans << endl;

  return 0;
}
