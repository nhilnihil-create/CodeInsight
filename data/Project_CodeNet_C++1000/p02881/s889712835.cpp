#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

vector<ll> divisor(ll n){
  vector<ll> res;
  for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  return res;
}
int main(){
  cout << setprecision(10);
  ll N; cin >> N;
  auto div = divisor(N);

  ll ans = N - 1;
  for(auto x: div){
    ll y = N / x;
    ll tmp = x-1 + y-1;

    ans = min(tmp, ans);
  }
  cout << ans << endl;
}
