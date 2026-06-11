#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define dl double long
const int INF=0x3fffffff;
const ll MOD=1000000007;
const ll MODD=998244353;
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
ll gcd(ll a, ll b) { return (b > 0) ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a*b/gcd(a, b); }

using ipair = pair<ll, ll>;

int main()
{
  ll N, K;
  vector<ipair> v;
  cin >> N >> K;
  if((N-1)*(N-2)/2 < K){
    cout << "-1" << "\n";
  }
  else{
    REP(i, 1, N) v.push_back({i, N});
    ll max = (N-1)*(N-2)/2-K;
    ll ci=1, cj=2;
    rep(i, max){
      v.push_back({ci, cj});
      ++cj;
      if(cj == N){
        ++ci;
        cj = ci + 1;
      }
    }
    cout << v.size() << "\n";
    for(auto a: v){
      cout << a.first << " " << a.second << "\n";
    }
  }
}
