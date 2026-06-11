#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;
//const int INF = 1001001001;

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main(void){
    ll n;
    cin >> n;
    auto v=divisor(n);
    ll ans=INF;
    REP(i,v.size()/2){
        if(ans>v[i]+v[v.size()-1-i])
            ans=v[i]+v[v.size()-1-i];
    }
    if(v.size()%2==1)
        if(ans>v[v.size()/2]*2)
            ans=v[v.size()/2]*2;
    cout << ans-2;
    return 0;
}