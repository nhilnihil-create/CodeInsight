#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
/* clang-format on */

int main() { 
  ll n;
  cin >> n;
  vector<ll> a(n),p(n),q(n);
  REP(i, n) { cin >> p[i]; }
  REP(i, n) { cin >> q[i]; }
  REP(i, n) { a[i] = i + 1; }
  ll cp = 1, cq = 1;
  ll ansp=0, ansq=0;
  do {
    if (ansp * ansq != 0) break;
    if (a == p) ansp = cp;
    if (a == q) ansq = cq;
    cp++;
    cq++;
    // DEBUGS(a);
  } while (next_permutation(ALL(a)));
  cout << abs(ansp - ansq) << endl;
  
  return 0;
}
