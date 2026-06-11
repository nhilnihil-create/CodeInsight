#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

bool C(ll K, ll target, const vector<ll>& v, const vector<ll>& w){
  ll cnt = 0;
  rep(i,v.size()){
    ll a = v[i];
    ll b = w[i];

    if(a*b>target){
      cnt += a - (target/b);
    }
  }
  return cnt > K;
}

int main(){
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> v, w;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
  }
  sort(ALLOF(v));
  rep(i,N){
    ll a;
    cin >> a;
    w.push_back(a);
  }
  sort(ALLOF(w));
  reverse(ALLOF(w));

  ll lb = -1, ub = (ll)(1e18);
  while(ub-lb>1){
    ll mid = lb + (ub-lb)/2;
    if(C(K,mid,v,w)) lb = mid;
    else ub = mid;
  }

  cout << ub << endl;
  
  return 0;
}


