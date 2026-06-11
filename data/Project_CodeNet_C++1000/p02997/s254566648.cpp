#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()


int main(){
  ll N,K,x=1,y=2;
  cin >> N >> K;
  if(K>((N-2)*(N-1))/2){
    cout << -1 << endl;
    return 0;
  }
  cout << (N*(N-1))/2-K << endl;
  rep(i,N-1){
    cout << i+1 << " " << N << endl;
  }
  rep(i,((N-2)*(N-1))/2-K){
    cout << x << " " << y << endl;
    y++;
    if(y==N){
      x++;
      y=x+1;
    }
  }
    
}