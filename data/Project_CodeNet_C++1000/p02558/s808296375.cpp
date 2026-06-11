
#include <atcoder/all>
#include <bits/stdc++.h>

#define rep(i,n)  for(int i = 0; i < (int)(n); i++)
#define sz(x)     ((int)(x).size())
#define all(x)    (x).begin(),(x).end()

using ll = long long;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }

int main (void) {
 std::cin.tie(0);  std::ios::sync_with_stdio(false);
 int n; std::cin >> n;
 atcoder::dsu uf(n);

 int Q; std::cin >> Q;
 rep(i,Q) {
   int t, u, v; std::cin >> t >> u >> v;
   if ( t == 0 ) uf.merge(u,v);
   else {
     if ( uf.same(u,v) ) std::cout << 1 << std::endl;
     else std::cout << 0 << std::endl;
   }
 }
  return 0;
}

