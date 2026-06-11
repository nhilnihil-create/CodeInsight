#include <bits/stdc++.h>
#include <string>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PL;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/

ll N, M, V, P;
ll a[MAX];

ll ok(ll K) {
  if(K<P) return 1;
  if(a[K]+M<a[P-1]) return 0;
  
  ll tot=(P-1)*M+(N-K)*M;
  for(ll i=P-1; i<K; i++) tot+=min(M, a[K]+M-a[i]);
  return tot>=M*V;
}


int main(void) {
  ll i, j, k;
  
  cin >> N >> M >> V >> P;
  
  for(i=0; i<N; i++) cin >> a[i];
  sort(a, a+N);
  reverse(a, a+N);
  
  ll l=-1, r=N;
  while(l+1<r) {
    ll m=(l+r)/2;
    if(ok(m)) l=m;
    else r=m;
  }
  
  pt(r);
}
