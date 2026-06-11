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



int main(void) {
  ll i, j, k;
  ll M;
  cin >> M;
  
  ll D=0, S=0;
  for(i=0; i<M; i++) {
    ll d, c;
    cin >> d >> c;
    D+=c;
    S+=d*c;
  }
  
  pt(D-1+(S-1)/9);
  
  
}

