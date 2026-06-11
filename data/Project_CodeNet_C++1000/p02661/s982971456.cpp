#include <bits/stdc++.h>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
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
  ll a[MAX*2], b[MAX*2];
  
  cin >> N;
  for(i=0; i<N; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a, a+N);
  sort(b, b+N);
  
  
  if(N&1) {
    pt(b[N/2]-a[N/2]+1);
  }else {
    double A=(a[N/2-1]+a[N/2])/2.0;
    double B=(b[N/2-1]+b[N/2])/2.0;
    ll ans=(B-A)*2+1;
    pt(ans);
  }
  
  
  
  
  
  
}
 
 


