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
  
  ll N, M, K;
  ll a[MAX*2], b[MAX*2];
  ll sa[MAX*2], sb[MAX*2];
  
  cin >> N >> M >> K;
  for(i=1; i<=N; i++) {
    cin >> a[i];
    sa[i]=sa[i-1]+a[i];
  }
  for(i=1; i<=M; i++) {
    cin >> b[i];
    sb[i]=sb[i-1]+b[i];
  }
  
  ll ans=0;
  for(i=0; i<=N; i++) {
    ll rem=K-sa[i];
    if(rem<0) continue;
    
    ll p=upper_bound(sb, sb+M+1, rem)-1-sb;
    chmax(ans, i+p);
  }
  
  pt(ans);
  
}
 
 


