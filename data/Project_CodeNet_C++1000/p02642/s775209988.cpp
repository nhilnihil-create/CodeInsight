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
  ll a[MAX*2]={};
  
  map<ll, ll> f;
  map<ll, ll> cnt;
  for(i=1; i<=N; i++) {
    cin >> a[i];
    f[a[i]]=1;
    cnt[a[i]]++;
  }
  sort(a, a+N+1);
  
  ll ans=0;
  for(i=1; i<=N; i++) {
    if(a[i-1]==a[i]) continue;
    if(f[a[i]]==0) continue;
    for(j=a[i]*2; j<MAX*10; j+=a[i]) f[j]=0;
  }
  
  
  for(i=1; i<=N; i++) if(cnt[a[i]]==1 && f[a[i]]) ans++;
  pt(ans);
  
  
}
