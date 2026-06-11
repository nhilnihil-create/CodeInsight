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



int main(void) {
  ll t1, t2;
  ll a1, a2, b1, b2, c1, c2, t;
  cin >> t1 >> t2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  c1=a1-b1;
  c2=a2-b2;
  
  ll P=c1*t1, Q=c2*t2;
  if(P>0) {
    P*=-1; Q*=-1;
  }
  
  if(P+Q<0) {
    pt(0);
  }else if(P+Q==0) {
    pt("infinity");
  }else {
    pt(abs(P)/(P+Q)*2+(abs(P)%(P+Q)!=0));
  }
  
}



