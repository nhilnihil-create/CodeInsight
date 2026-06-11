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
  ll samecount = 0;
  REP(i,n) cin >> a[i];
  REP(i,n){
    cin >> b[i];
    c[i] = b[i];
  }
  priority_queue<pair<ll,ll>> que;
  REP(i,n){
    if(a[i]!=b[i] && b[i]>b[(i-1+n)%n]+b[(i+1+n)%n]) que.push(make_pair(b[i],i));
    if(a[i]==b[i]) samecount++;
  }
  ll ans = 0;
  while(que.size()>0){
    ll num = que.top().first;
    ll ind = que.top().second;
    ll ip = (ind-1+n)%n;
    ll in = (ind+1+n)%n;
    ll diff = c[ip]+c[in];
    que.pop();
    ll tmp = (c[ind]-a[ind])/diff;
    ans += tmp;
    c[ind] -= tmp*diff;
    if(c[ind]==a[ind]) samecount++;
    if(c[ip]>a[ip] && c[ip]>c[(ip-1+n)%n]+c[ind]) que.push(make_pair(c[ip],ip));
    if(c[in]>a[in] && c[in]>c[(in+1+n)%n]+c[ind]) que.push(make_pair(c[in],in));
  }
  if(samecount==n) cout << ans<< endl;
  else cout << -1 << endl;
  return 0;
}
