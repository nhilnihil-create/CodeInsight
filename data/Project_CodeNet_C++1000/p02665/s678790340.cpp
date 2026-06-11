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
static const ll MOD=998244353;

//for(i=0; i<N; i++) cin >> a[i];



int main(void) {
  ll i, j, k;
  
  ll N;
  cin >> N;
  ll a[MAX];
  
    
  for(i=0; i<=N; i++) cin >> a[i];
  
  if(N==0) {
    pt(2*(a[0]==1)-1);
    return 0;
  }
  
  if(a[0]>0) { pt(-1); return 0; }
  
  ll c[MAX]={}, f[MAX];
  f[0]=1;
  for(i=1; i<=N; i++) f[i]=INF;
  for(i=1; i<=N; i++) {
    chmin(f[i], f[i-1]*2-a[i]);
    if(f[i]<0) { pt(-1); return 0; }
  }
  
  c[N+1]=0;
  for(i=N; i>=0; i--) {
    if(f[i]*2<c[i+1]) { pt(-1); return 0; }
    c[i]=min(f[i], c[i+1])+a[i];
  }
  
  
  ll ans=0;
  for(i=0; i<=N; i++) ans+=c[i];
  pt(ans);
  
}
 
 


