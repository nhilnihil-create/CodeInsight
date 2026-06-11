#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i= (a); i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
unordered_map<ll, ll> prime_factorization(long long n) {
  //map<ll,ll> first=素因数 second=first素因数の数
  unordered_map<ll, ll> res;
  for (int i = 2; i  <= n/i; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if(n != 1) res[n]++;
  return res;
}
int main()
{
  ll A,B;
  cin >> A >> B;
  unordered_map<ll, ll> a = prime_factorization(A);
  ll ans = 0;
  for(auto s:a){
    if (B % s.first == 0) ans++;
  }
  ans++;
  cout << ans << "\n";
}