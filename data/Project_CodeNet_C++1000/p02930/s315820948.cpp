#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/


ll N;
ll g[555][555];
ll clr=0;

void rec(ll l, ll r, ll c) {
  if(l+1==r) return;
  
  ll mid=(l+r)/2;
  rec(l, mid, c+1);
  rec(mid, r, c+1);
  
  ll i, j;
  for(i=l; i<mid; i++) {
    for(j=mid; j<r; j++) {
      g[i][j]=c;
    }
  }
  
  
}

int main(void) {
  ll i, j, k;
  cin >> N;
  
  memset(g, -1, sizeof(g));
  rec(0, N, 1);
  
  for(i=0; i<N; i++) {
    for(j=i+1; j<N; j++) {
      cout << g[i][j] << " ";
    }
    pt("");
  }
  
}

