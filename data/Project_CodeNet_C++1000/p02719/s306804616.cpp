#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  ll N, K; cin >> N >> K;
  ll ans = N%K;
  ans = min(ans, abs(ans-K));
  
  cout << ans << endl;
  return 0;
}