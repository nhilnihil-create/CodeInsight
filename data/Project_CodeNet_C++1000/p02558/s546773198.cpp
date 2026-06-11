#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;;
using namespace atcoder;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define F first
#define S gsecond
#define mp make_pair
#define pb push_back
const int MOD = 1000000007;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,q;cin >> n>> q;
  dsu d(n);
  ll t,u,v;
  rep(i,q){
      cin >> t >> u >> v;
      if(t==0){
          d.merge(u,v);
      }else{
          cout << d.same(u,v) << endl;
      }
  }
}