#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

vector<ll> divisor(ll n){
  vector<ll> ret;
  for(ll i=1; i*i<=n; i++){
    if(n%i==0){
      ret.push_back(i);
      if(i!=n/i) ret.push_back(n/i);
    }
  }
  return ret;
}

bool check(const vector<ll>& v, ll K, ll x){
  vector<ll> w;
  rep(i,v.size()){
    w.emplace_back(v[i]%x);
  }
  sort(ALLOF(w));

  ll cnt = 0;
  int i=0, j=w.size()-1;
  while(i<j){
    ll a = w[i];
    ll b = x-w[j];
    ll m = min(a,b);
    w[i]-=m;
    w[j]+=m;
    w[j]%=x;

    cnt += m;
    
    if(w[i]==0) i++;
    if(w[j]==0) j--;
  }

  bool flg = true;
  rep(i,w.size()) if(w[i] != 0) flg = false;
  return flg && cnt <= K;
}


int main(){
  ll N, K;
  cin >> N >> K;
  vector<ll> v;
  ll sum = 0;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
    sum += a;
  }

  vector<ll> dv = divisor(sum);

  ll ret = 0;
  rep(i,dv.size()){
    if(check(v,K,dv[i])){
      ret = max(ret, dv[i]);
    }
  }

  cout << ret << endl;
  
  return 0;
}
