#include <bits/stdc++.h>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define moca(a, s, b) a=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


//for(i=0; i<N; i++) cin >> a[i];


int main(void) {
  ll i, j, k;
  
  ll N;
  cin >> N;
  
  
  ll ans=0;
  for(i=1; i<=N; i++) {
    ll c=N/i;
    ans+=i*c*(c+1)/2;
  }
  
  pt(ans);
}
