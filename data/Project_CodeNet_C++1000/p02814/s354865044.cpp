#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b){return (b==0?a:gcd(b,a%b));}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> v;

  bool ng = false;
  ll x = 0;
  rep(i,N){
    int a;
    cin >> a;
    v.push_back(a);

    int cnt = 0;
    while(a%2==0){
      cnt++;
      a/=2;
    }
    if(x == 0){
      x = cnt;
    }else{
      if(x != cnt){
        ng = true;
      }
    }
  }

  if(ng){
    cout << 0 << endl;
    return 0;
  }

  ll p = 1;
  rep(i,x-1) p *= 2;
  

  rep(i,N){
    v[i] /= p;
  }
  
  ll l = 1;
  rep(i,N){
    ll a = v[i]/2;
    
    l = lcm(l, a);
    if(l > M){
      cout << 0 << endl;
      return 0;
    }
  }

  if(p > M){
    cout << 0 << endl;
    return 0;
  }
  if(p*l > M){
    cout << 0 << endl;
    return 0;
  }
  
  ll lb = 0, ub = 1e10;
  while(ub-lb>1){
    ll mid = (ub-lb)/2 + lb;
    if(2*p*l*mid-p*l <= M) lb = mid;
    else ub = mid;
  }
  
  cout << lb << endl;

  return 0;
}

