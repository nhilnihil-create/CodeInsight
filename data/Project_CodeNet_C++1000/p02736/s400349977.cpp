#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MOD=1e9+7;
static const ll MAX=101010;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/


ll twocnt(ll n) {
  ll res=0;
  while(n%2==0) {res++; n>>=1;}
  return res;
}

ll a[MAX*10];
ll tc[MAX*10];

int main(void) {
  ll i, j, k, l;
  
  ll N;
  cin >> N;
  string s;
  cin >> s;
  
  for(i=0; i<N; i++) a[i]=s[i]-'0'-1;
  
  for(i=1; i<N; i++) tc[i]=tc[i-1]+twocnt(i);
  
  ll m=0;
  for(i=0; i<N; i++) {
    ll c=tc[N-1]-tc[i]-tc[N-1-i];
    m^=(a[i]&1)*(c==0);
  }
  
  
  if(m) {
    pt(1);
  }else {
    for(i=0; i<N; i++) {
      if(a[i]==1) {
        pt(0); return 0;
      }
    }
    
    for(i=0; i<N; i++) a[i]>>=1;
    
    m=0;
    for(i=0; i<N; i++) {
      ll c=tc[N-1]-tc[i]-tc[N-1-i];
      m^=(a[i]&1)*(c==0);
    }
    
    if(m) pt(2);
    else  pt(0);
    
  }
  
  
}


