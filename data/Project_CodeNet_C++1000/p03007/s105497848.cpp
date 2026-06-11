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


int main(void) {
  ll i, j, k, l;
  
  ll N;
  cin >> N;
  ll s=0;
  ll a[MAX];
  memset(a, 999, sizeof(a));
  for(i=0; i<N; i++) {
    cin >> a[i];
    s+=abs(a[i]);
  }
  sort(a, a+N);
  
  if((a[0]<0 && a[N-1]>0)) {
    pt(s);
    for(k=0; a[k]<=0; k++);
    
    for(i=k; i<N-1; i++) {
      pt(a[0]<<" "<<a[i]);
      a[0]-=a[i];
    }
      
    for(i=0; i<k; i++) {
      pt(a[N-1]<<" "<<a[i]);
      a[N-1]-=a[i];
    }
    
  }else if(a[0]>=0) {
    pt(s-a[0]*2);
    for(i=1; i<N-1; i++) {
      pt(a[0]<<" "<<a[i]);
      a[0]-=a[i];
    }
    pt(a[N-1]<<" "<<a[0]);
    
  }else {
    pt(s-abs(a[N-1])*2);
    for(i=0; i<N-1; i++) {
      pt(a[N-1]<<" "<<a[i]);
      a[N-1]-=a[i];
    }
      
  }
  
  
}


