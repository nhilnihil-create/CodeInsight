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

pll reduce(ll d, ll c){
  ll ret = 0;
  while(c>=10){
    ll a = c/10;
    ll b = c%10;
    ret += a*(d+9);
    c = a+b;
  }
  ll tmp = 0;
  REP(i,c){
    tmp += d;
    if(i!=0) ret ++;
    if(tmp>=10){
      ret ++;
      tmp = tmp/10 + tmp%10;
    }
  }
  //cout << d << "," << c << "-> " << tmp << "," << ret << endl; 
  return {tmp,ret};
}
int main() {
  ll n;
  cin >> n;
  vl input(n);
  ll ans = 0;
  REP(i,n){
    ll c,d;
    cin >> d >> c;
    pll ret = reduce(d,c);
    input[i] = ret.first;
    ans += ret.second;
  }
  ll tmp = 0;
  REP(i,n){
    tmp += input[i];
    if(i!=0) ans ++;
    if(tmp>=10){
      ans ++;
      tmp = tmp/10 + tmp%10;
    }
  }
  cout << ans << endl;
  return 0;
}
