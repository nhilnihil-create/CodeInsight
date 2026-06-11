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
  ll N;
  cin >> N;
  vec A(N);
  rep(i,N){
    cin >> A.at(i);
  }
  sort(all(A));
  reverse(all(A));
  ll ans=0;
  rep(i,N-1){
    ans+=A.at((i+1)/2);
  }
  cout << ans << endl;
}
          
          
        
  