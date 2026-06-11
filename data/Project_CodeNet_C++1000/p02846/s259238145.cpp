/*{{{*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
// pll pp; -> (pp.first,pp.second)
// vector<vl> pp(n,vl(2)); sort(pp.begin(),pp.end(),[](vl a,vl b){return a[0]<b[0];});

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define RREP(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define FOR(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define FORR(i,a,b) for(ll (i)=(b)-1;(i)>=(a);(i)--)
#define DEBUG(x) cout << #x << ": " << x << endl
#define CHMAX(a,b) a=max((a),(b))
#define CHMIN(a,b) a=min((a),(b))
/*}}}*/
int main() {
  ll t1,t2,a1,a2,b1,b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

  if(a1*t1 + a2*t2 == b1*t1 + b2*t2){
    cout << "infinity" << endl;
    return 0;
  }
  
  // a is faster
  if(a1*t1 + a2*t2 < b1*t1 + b2*t2){
    swap(a1,b1);
    swap(a2,b2);
  }

  ll peak = (a1-b1)*t1;
  ll diff = (a1-b1)*t1 + (a2-b2)*t2;

  if(peak > 0){
    cout << 0 << endl;
    return 0;
  }

  peak = -peak;

  ll ans = peak/diff*2;

  if(peak%diff>0) ans ++;

  //cout << fixed << setprecision(10);
  cout << ans << endl;
  return 0;
}
