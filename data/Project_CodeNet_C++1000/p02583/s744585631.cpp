#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll n;
  cin >> n;
  vector<ll> l(n);
  REP(i, n) cin >> l[i];
  ll ans = 0;
  REP(i, n){
    FOR(j, i+1, n){
      FOR(k, j+1, n){
        if(l[i] == l[j] || l[i] == l[k] || l[j] == l[k]) continue;
        if(l[i]+l[j] > l[k] && l[i]+l[k] > l[j] && l[j]+l[k] > l[i]) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}