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
  ll n;
  cin >> n;
  vl a(n),b(n),c(n);
  REP(i,n) cin >> a[i];
  ll samecount = 0;
  REP(i,n){
    cin >> b[i];
    c[i] = b[i];
    if(a[i]==b[i]) samecount++;
  }
  vl cand;
  REP(i,n){
    if(c[i]!=a[i] && c[i]>c[(i-1+n)%n]+c[(i+1)%n]) cand.push_back(i);
  }
  ll ans = 0;
  while(cand.size()>0){
    //cout << "cand : ";
    //REP(i,cand.size()) cout << cand[i] << ",";
    //cout << endl;
    //REP(i,n) cout << c[i] << ",";
    //cout << endl;
    //cout << endl;
    vl nextCand;
    for(int i=0;i<(ll)cand.size();i++){
      ll ind = cand[i];
      ll diff = c[(ind-1+n)%n]+c[(ind+1)%n];
      ll tmp = (c[ind]-a[ind])/diff;
      ans += tmp;
      c[ind] -= tmp*diff;
      if(c[ind]==a[ind]){
        samecount++;
      }
      if(c[(ind-1+n)%n]!=a[(ind-1+n)%n] && c[(ind-1+n)%n]>c[(ind-2+n)%n]+c[ind]) nextCand.push_back((ind-1+n)%n);
      if(c[(ind+1+n)%n]!=a[(ind+1+n)%n] && c[(ind+1+n)%n]>c[(ind+2+n)%n]+c[ind]) nextCand.push_back((ind+1+n)%n);
    }
    cand = nextCand;
  }
  if(samecount==n) cout << ans<< endl;
  else cout << -1 << endl;
  return 0;
}
